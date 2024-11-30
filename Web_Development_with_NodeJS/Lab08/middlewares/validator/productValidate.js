const { body } = require('express-validator');
const { updateProduct } = require('../../controllers/productController');

module.exports = {
    createProduct: [
        body('name')
            .notEmpty()
            .withMessage('Please enter the name of product')
            .isLength({min: 5})
            .withMessage('The name of product must be at least 5 characters'),
        body('category')
            .custom((value) => {
                if(!['Phone', 'Tablet', 'Laptop', 'Headphone'].includes(value))
                    throw new Error('The category is invalid');
                return true;
            }),
        body('price')
            .notEmpty()
            .withMessage('Please enter price of product')
            .isInt({min: 0, max: 900000000000})
            .withMessage('The price of product is over allowed range - (0 to 9 hundred billion)'),
    ],
    updateProduct: [
        body('name')
            .notEmpty()
            .withMessage('Please enter the name of product')
            .isLength({min: 5})
            .withMessage('The name of product must be at least 5 characters'),
        body('category')
            .custom((value) => {
                if(!['Phone', 'Tablet', 'Laptop', 'Headphone'].includes(value))
                    throw new Error('The category is invalid');
                return true;
            }),
        body('price')
            .notEmpty()
            .withMessage('Please enter price of product')
            .isInt({min: 0, max: 900000000000})
            .withMessage('The price of product is over allowed range - (0 to 9 hundred billion)'),
    ]
}