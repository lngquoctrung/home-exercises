const http = require("http");
const fs = require("fs");
const qs = require("querystring");

const PORT = 5050;

console.clear();

async function read_html_file(file_name){
    const file_path = __dirname + "/" + file_name + ".html";
    return await fs.promises.readFile(file_path);
}

const server = http.createServer(async (req, res) => {
    res.writeHead(200, {
        "Content-Type": "text/html; charset=utf-8",
    })
    if(req.method === "GET"){
        if(req.url === "/"){
            const html_content = await read_html_file("login");
            res.write(html_content);
        }
        else if(req.url === "/login"){
            res.write("<h2>Phương thức GET không được hỗ trợ</h2>");
        }
        else{
            res.write("<h2>Đường dẫn không hợp lệ</h2>");
        }
        res.end();
    }
    else{
        let data = "";
        req.on("data", d => data += d.toString());
        req.on("end", () => {
            const {email, pass} = qs.parse(data);
            // Use regular expression to check format email
            /*
                (\w+)@(\w+)\.(\w+):
                - (\w+)@: contains at least one word be @ symbol. -> Name
                - (\w+)\.(\w+): contains at least one word front and back of . symbol -> Domain
                For example: aaa@bbb.ccc
            */
            if(!email.match(/(\w+)@(\w+)\.(\w+)/)){
                res.write("<h2>Email không hợp lệ</h2>");
            }
            else if(pass.length < 6){
                res.write("<h2>Mật khẩu không hợp lệ</h2>");
            }
            else{
                res.write("<h2>Đăng nhập thành công</h2>");
            }
            res.end();
        });
    }
});

server.listen(PORT, () => console.log(`Server is running on https://localhost:${PORT}/`));