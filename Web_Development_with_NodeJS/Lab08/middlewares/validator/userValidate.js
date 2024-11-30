const { body } = require('express-validator');

//  Middleware kiểm tra data hợp lệ hay không
const userValidator = {
    login: [
        body('email')
            .notEmpty()
            .withMessage('Please enter your email')
            .isEmail()
            .withMessage('Email is invalid'),

        body('password')
            .notEmpty()
            .withMessage('Please enter your password')
    ],
    register: [
        body('username')
            .notEmpty()
            .withMessage('Please enter your name')
            .isLength({min: 5})
            .withMessage('The username must be at least 5 characters'),

        body('email')
            .notEmpty()
            .withMessage('Please enter your email')
            .isEmail()
            .withMessage('Your email is invalid'),

        body('password')
            .notEmpty()
            .withMessage('Please enter your password')
            .isLength({min: 5})
            .withMessage('The password must be at least 5 characters'),
        
        body('cfmPassword')
            .custom((value, {req}) => {
                if(value !== req.body.password){
                    throw new Error('Password does not match')
                }
                return true;
            })
    ]
}

module.exports = userValidator;