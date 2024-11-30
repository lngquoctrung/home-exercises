const jwt = require('jsonwebtoken');

class TokenHelper{
    #secretKey;

    constructor(secretKey, expiresIn){
        this.#secretKey = secretKey,
        this.expiresIn = expiresIn
    }

    sign(data){
        return jwt.sign(data, this.#secretKey, {expiresIn: this.expiresIn});
    }

    verify(token){
        return jwt.verify(token, this.#secretKey);
    }
}

const accessTokenHelper = new TokenHelper(process.env.ACCESS_TOKEN_KEY, '15m');
const refreshTokenHelper = new TokenHelper(process.env.REFRESH_TOKEN_KET, '7h');

module.exports = {accessTokenHelper, refreshTokenHelper};