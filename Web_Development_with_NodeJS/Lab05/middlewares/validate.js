const {validationResult} = require('express-validator');

const validate = (req, res, next) => {
    const errors = validationResult(req);
    if(!errors.isEmpty()){
        // Lấy lỗi đầu tiên của mỗi trường
        const uniqueErrors = {};
        errors.array().forEach(error => {
            if (!uniqueErrors[error.path]) {
                uniqueErrors[error.path] = error.msg;
            }
        });

        // Render lại form với dữ liệu cũ và thông báo lỗi
        return res.render('add', {
            ...req.body, // Giữ lại các giá trị đã nhập
            isError: true,
            errorMsg: Object.values(uniqueErrors)[0], // Chỉ lấy thông báo lỗi đầu tiên
        });
    }
    next();
}

module.exports = validate