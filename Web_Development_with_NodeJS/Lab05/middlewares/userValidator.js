const {body} = require('express-validator');

const userValidator = {
    createUser: [
        body('fullname')
            .trim()
            .notEmpty()
            .withMessage('Username không được để trống')
            .isLength({min: 3, max: 50})
            .withMessage('Username chỉ nằm trong khoản từ 3-50 ký tự')
            .matches(/^[a-zA-Z0-9_]+$/)
            .withMessage('Username chỉ được chứa chữ, số và dấu gạch dưới'),
        body('gender')
            .isIn(['male', 'female'])
            .withMessage('Vui lòng chọn giới tính'),
        body('age')
            .isInt({min: 1, max: 100})
            .withMessage('Tuổi phải nằm trong khoản 1 - 100'),
        body('email')
            .trim()
            .notEmpty()
            .withMessage('Email không được để trống')
            .isEmail()
            .withMessage('Email không hợp lệ'),
    ]
}

module.exports = userValidator;