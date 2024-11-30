const mongoose = require('mongoose');

const itemSchema = new mongoose.Schema({
    product: {
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Product',
        require: true,
    },
    quantity: {
        type: Number,
        require: true,
        default: 1,
    },
    price: {
        type: Number,
        require: true,
    },
});

const orderSchema = new mongoose.Schema({
    user: {
        type: mongoose.Schema.Types.ObjectId,
        ref: 'User',
    },
    products: [itemSchema],
    totalPrice: {
        type: Number,
        require: true,
        default: 0,
    },
    status: {
        type: String,
        require: true,
        default: 'pending'
    },
    createdAt: {
        type: Date,
        default: Date.now(),
    },
    updateAt: {
        type: Date,
        default: Date.now(),
    }
});

module.exports = mongoose.model('Order', orderSchema);