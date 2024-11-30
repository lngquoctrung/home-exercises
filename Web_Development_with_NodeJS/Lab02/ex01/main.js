const http = require("http");
const fs = require("fs");
const qs = require("querystring");

const PORT = 5050;

// Clear terminal when restarting server
console.clear();

async function read_html_file(file_name){
    const file_path = __dirname + "/" + file_name + ".html";
    return await fs.promises.readFile(file_path);
}

// Create server
const server = http.createServer(async (req, res) => {
    // Define headers of HTTP response
    res.writeHead(200, {                // 200 is successful response
        "Content-Type": "text/html; charset=utf-8",    // the response contains HTML content
    })

    // Case if method is GET
    if(req.method === "GET"){
        // Check whether the url is valid or not
        if(req.url === "/"){
            const html_content = await read_html_file("index");
            res.write(html_content);
        }
        else{
            res.write("<h2>Đường dẫn không hợp lệ</h2>");
        }
        res.end();
    }
    // Case if method is POST
    else{
        let data = "";
        // Collect data
        req.on("data", d => data += d.toString());
        req.on("end", () => {
            const {number1, number2, operation} = qs.parse(data);
            if(number1 === "" || number2 === ""){
                res.write("<h2>Bạn chưa nhập đủ số</h2>");
            }
            else if(operation === ""){
                res.write("<h2>Bạn chưa nhập phép toán</h2>");
            }
            else if(number2 === "0" && operation === "div"){
                res.write("<h2>Không thể chia cho không</h2>");
            }
            else{
                switch(operation){
                    case "add":
                        res.write(`${number1} + ${number2} = ${number1 + number2}`);
                        break;
                    case "sub":
                        res.write(`${number1} - ${number2} = ${number1 - number2}`);
                        break;
                    case "mul":
                        res.write(`${number1} * ${number2} = ${number1 * number2}`);
                        break;
                    case "div":
                        res.write(`${number1} / ${number2} = ${number1 / number2}`);
                        break;
                }
            }
            res.end();
        });
    }
    /* 
    Don't put res.end() below req.on() because the callback function of req.on is Stream,
        so the block code will be run last. If res.end() is putted below res.on, then the block
        code into res.on() will be not executed.
    */
});

server.listen(PORT, () => {
    console.log(`The website started on http://localhost:${PORT}/`);
});