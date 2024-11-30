const { body } = require('express-validator');
const mongoose = require('mongoose');

module.exports = {
    createOrder: [
        body('product')
            .notEmpty()
            .withMessage('Please enter the product')
            .custom((value) => {
                if(!mongoose.Types.ObjectId.isValid(value)){
                    throw new Error('The id of product is invalid');
                }
                return true;
            })
    ]
}