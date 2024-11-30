const mongoose = require('mongoose');
const bcryptjs = require('bcryptjs');

const userSchema = new mongoose.Schema({
    username: {
        type: String,
        require: true,
    },
    email: {
        type: String,
        unique: true,
        require: true,
    },
    password: {
        type: String,
        require: true,
    },
    refreshToken: {
        type: String,
        require: true,
    }
});

userSchema.pre('save', async function (next) {
    // Chỉ hash password khi có sự thay đổi
    if(!this.isModified('password')){
        next();
    }
    try{
        const SALT_ROUNDS = process.env.SALT_ROUNDS;
        const SALT = await bcryptjs.genSalt(parseInt(SALT_ROUNDS));
        this.password = await bcryptjs.hash(this.password, SALT);
        next();
    }
    catch(error) {
        next(error);
    }
});

userSchema.methods.comparePassword = async function(plainPassword){
    return await bcryptjs.compare(plainPassword, this.password);    
}

module.exports = mongoose.model('User', userSchema);