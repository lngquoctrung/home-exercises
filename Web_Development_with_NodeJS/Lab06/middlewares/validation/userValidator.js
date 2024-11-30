const { body } = require('express-validator');

module.exports = {
    // * Middleware check form data for login
    login: [
        body('name')
            .trim()
            .notEmpty()
            .withMessage('Please enter your name')
            .matches(/^[A-Za-z0-9]+$/)
            .withMessage('Your name is invalid'),

        body('pass')
            .trim()
            .notEmpty()
            .withMessage('Please enter your password')
    ],
    // * Middleware check form data for register
    register: [
        body('name')
            .trim()
            .notEmpty()
            .withMessage('Please enter your name')
            .isLength({min: 5, max: 100})
            .withMessage('Your name must be in range 3-100 characters')
            .matches(/^[A-Za-z0-9\_]+$/)
            .withMessage('Name must contains only numbers, letters, and underscores'),
        
        body('email')
            .trim()
            .notEmpty()
            .withMessage('Please enter your email')
            .isEmail()
            .withMessage('Your email is invalid'),
        
        body('pass')
            .trim()
            .notEmpty()
            .withMessage('Please enter your password')
            .isLength({min: 6})
            .withMessage('Your password must have at least 6 characters'),
        
        body('cfmPass')
            .trim()
            .notEmpty()
            .withMessage('Please enter confirm password')
            .custom((value, {req}) => {
                if(value !== req.body.pass){
                    throw new Error('Confirmation password does not match');
                }
                return true;
            })
    ]
}