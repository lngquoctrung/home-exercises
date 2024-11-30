const mongoose = require('mongoose');

const schema = new mongoose.Schema({
    name: {
        type: String,
        require: true,
        unique: true,
    },
    email: {
        type: String,
        require: true,
        unique: true,
    },
    pass: {
        type: String,
        require: true,
    },
    refreshToken: {
        type: String,
    }
})

module.exports = mongoose.model('user', schema);