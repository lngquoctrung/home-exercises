require('dotenv').config();

// Xác thực người dùng đã đăng nhập hay chưa.
// Yêu cầu người dùng phải đăng nhập mới được thực hiện
//   các tác vụ khác.
function authenticationCheck(req, res, next){
    // Kiểm tra trong session đã lưu thông tin đăng nhập hay chưa
    if(req.session.user){
        // Trường hợp đã đăng nhập mà đường dẫn là '/login' thì
        //   chuyển hướng về trang chủ.
        if (req.path === '/login') res.redirect('/');
        // Các đường dẫn khác đều hợp lệ
        else next();
    }
    // Trường hợp người dùng chưa đăng nhập
    else {
        // Nếu đường đẫn là '/login' thì hợp lệ
        if (req.path === '/login') next();
        // Nếu đường dẫn khác thì yêu cầu phải quay về trang login
        else res.redirect('/login');
    }
}

// Kiểm tra login form khi gửi có hợp lệ hay không
function formValidation(req, res, next) {
    const user = req.body;
    // Hiển thị lỗi khi các input rỗng
    if (user.email === '') {
        res.render('login', {
                        isError: true,
                        errMsg: 'Vui lòng nhập email',
                    });
    }
    else if (user.password === '') {
        res.render('login', {
                        isError: true,
                        errMsg: 'Vui lòng nhập password',
                        email: user.email,
                    });
    }
    // Tất cả các ô đều được nhập thì chuyển qua middleware tiếp theo
    else {
        // Lưu các giá trị để middleware phía sau có thể sử dụng
        res.email = user.email;
        res.pass = user.password;
        // Chuyển sang middleware tiếp theo
        next();
    }
}

// Xác thực thông tin đăng nhập có hợp lệ hay không
// Tài khoản được định nghĩa trong file '.env' thay cho lấy
//   thông tin từ database.
function userAuthentication(req, res, next){
    // Trường hợp email hoặc mật khẩu không trùng khớp
    if (res.email !== process.env.ADMIN_EMAIL || res.pass !== process.env.ADMIN_PASS) {
        res.render('login', {
                        isError: true,
                        errMsg: 'Tài khoản không chính xác',
                        email: res.email,
                        pass: res.pass,
                    });
    }
    /*
        Các cookie và session hoạt động: https://medium.com/@hendelRamzy/how-session-and-cookies-works-640fb3f349d1
    */
    // Trường hợp thông tin đăng nhập hợp lệ
    else {
        // Lưu dữ liệu người dùng vào session
        req.session.user = res.email;
        // Gửi cookie `sessionID` về phía client
        res.cookie("sessionID", req.sessionID);
        // Đến trang chủ
        next();
    }
}

module.exports = {authenticationCheck, formValidation, userAuthentication};