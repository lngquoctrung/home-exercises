const http = require("http");
const fs = require("fs");
const qs = require("querystring");
const url = require("url");

const PORT = 5050;

console.clear();

let student_list = [
    {std_id: "1", std_name: "Ly Nguyen Quoc Trung", std_age: 18},
    {std_id: "2", std_name: "Nguyen Van A", std_age: 17},
];

function response_json(res, res_code, res_message, res_data=null){
    if(res_data) res.write(JSON.stringify({code: res_code, message: res_message, data: res_data}));
    else res.write(JSON.stringify({code: res_code, message: res_message}));
    res.end();
}

function is_existed(student_id){
    for(let student of student_list){
        if(student.std_id === student_id) 
            return true;
    }
    return false;
}

function is_valid(student){
    // Is ID empty
    if(!student.std_id){
        response_json(res, 208, "Add student unsuccessfully. ID is empty");
        return false;
    }
    // Is name empty
    else if(!student.std_name){
        response_json(res, 208, "Add student unsuccessfully. Name is empty");
        return false;
    }
    // Is age empty
    else if(!student.std_age){
        response_json(res, 208, "Add student unsuccessfully. Age is empty");
        return false;
    }
    // Is ID duplicated
    else if(is_existed(student.std_id)){
        response_json(res, 208, "Add student unsuccessfully. ID is existed");
        return false;
    }
    else if(student.std_age < 6 || student.std_age > 100){
        response_json(res, 208, "Add student unsuccessfully. Age is not appropriate");
        return false;
    }
    return true;
}

function find_student(id){
    for(let i = 0; i < student_list.length ;i++){
        if(student_list[i].std_id === id){
            return i;
        }
    }
    return -1;
}
    

const server = http.createServer((req, res) => {
    res.writeHead(200, {
        "Content-Type": "application/json",
    });
    const parse_url = url.parse(req.url);
    if(parse_url.pathname === "/students"){
        // Reponse data when method is GET
        if(req.method === "GET" && !parse_url.query){    
            response_json(res, 200, "Successfully", student_list);
        }
        // Add data when method is POST => Add student
        else if (req.method === "POST"){    
            let data = "";
            req.on("data", d => data += d.toString());
            req.on("end", () => {
                const {id, name, age} = qs.parse(data);
                const student = {std_id: id, std_name: name, std_age: parseInt(age, 10)};
                // Check input is whether valid or not
                if(is_valid(student)){
                    student_list.push(student);
                    response_json(res, 200, "Add student successfully", student);
                }
            });
        }
        else{
            response_json(res, 405, `Method ${req.method} is not supported`);
        }
    }
    else if(parse_url.pathname.match(/^\/students\/(\w+)(\/*)$/)){
        const student_id = parse_url.pathname.replace(/^\/students\//, "").replace(/\/*$/, "");
        // Handle method
        if(req.method === "GET" && !parse_url.query){
            let student_index = find_student(student_id);
            // Student is not existed
            if(student_index === -1) response_json(res, 209, "Student is not existed");
            response_json(res, 200, "Found", student_list[student_index]);
        }
        else if(req.method === "PUT"){
            let student_index = find_student(student_id);
            // Student is not existed
            if(student_index === -1) response_json(res, 209, "Student is not existed");
            let data = "";
            req.on("data", d => data += d.toString());
            req.on("end", () => {
                const {id, name, age} = qs.parse(data);
                if(!id && !name && !age) response_json(res, 208, "Update data of student unsuccessfully");
                if(id){
                    if(!is_existed(id)) student_list[student_index].std_id = id;
                    else response_json(res, 208, "ID is existed");
                }
                if(name) student_list[student_index].std_name = name;
                if(age) student_list[student_index].std_age = age;
                response_json(res, 200, "Update data of student successfully", student_list[student_index]);
            });
        }
        else if(req.method === "DELETE" && !parse_url.query){
            let student_index = find_student(student_id);
            // Student is not existed
            if(student_index === -1) response_json(res, 209, "Student is not existed");
            console.log(student_index)
            student_list.splice(student_index, 1);
            response_json(res, 200, "Remove student successfully");
        }
        else{
            response_json(res, 405, `Method ${req.method} is not supported`);
        }
    }

    // Response error message when url is not appropriate
    else{
        response_json(res, 404, "Not found");
    }
});

server.listen(PORT, () => console.log(`Server is running on https://localhost:${PORT}`));