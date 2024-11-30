const mongoose = require('mongoose');

const userSchema = new mongoose.Schema({
    email: {
        type: String,
        unique: true,
    },
    username: String,
    pass: String,
    refreshToken: String,
    googleId: String,
});

module.exports = mongoose.model('user', userSchema);