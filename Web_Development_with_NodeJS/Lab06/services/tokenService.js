const jwt = require('jsonwebtoken');

/**
 * Class use to manage token authentication
 * @class TokenService
 */
class TokenService{
    /**
     * Initialize token management service
     * @param {string} secret_key - Secrect key use to sign token
     * @param {string} expiresIn  - Token expiration time (e.g: '1h', '7d')
     * @throws {Error} If secret key is not provided
     */
    constructor(secret_key, expiresIn){
        if(!secret_key){
            throw new Error('Please provide secret key');
        }
        this.secret_key = secret_key;
        this.expiresIn = expiresIn;
    }

    /**
     * Create a new JWT token
     * @param {Object} data - Data use to encode into token 
     * @returns {string} JWT token signed
     * @example
     * const token = tokenService.createToken({ userId: 123 });
     */
    createToken(data){
        return jwt.sign(data, this.secret_key, {
            expiresIn: this.expiresIn,
        });
    }

    /**
     * Verify and decode token
     * @param {string} token - Token need to verify
     * @returns {Object} - Data is encoded from token
     * @throws {JsonWebTokenError} If token is invalid
     * @throws {JsonExpiredError} If token expired
     */
    verifyToken(token){
        return jwt.verify(token, this.secret_key);
    }
}

const accessTokenService = new TokenService(process.env.ACCESS_TOKEN_SECRET_KEY, '5m');
const refreshTokenService = new TokenService(process.env.REFRESH_TOKEN_SECRET_KEY, '12h');

module.exports = { accessTokenService, refreshTokenService }