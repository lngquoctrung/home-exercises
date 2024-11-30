const mongoose = require('mongoose');

const productSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    imageUrl: {
        type: String
    },
    category: {
        type: String,
    },
    price: {
        type: Number,
        required: true,
    }
});

module.exports = mongoose.model('Product', productSchema);