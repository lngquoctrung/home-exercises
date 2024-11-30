const { accessTokenHelper } = require('../../helpers/tokenHelper');
const ResponseHelper = require('../../helpers/responseHelper');

module.exports = (req, res, next) => {
    try{
        const accessToken = req.cookies.accessToken;
        if(!accessToken){
            return res
                .status(401)
                .json(ResponseHelper.error(401, 'Token has expired'));
        }
        else{
            const decode = accessTokenHelper.verify(accessToken);
            req.email = decode.email;
            return next();
        }
    }
    catch(error){
        return res
            .status(403)
            .json(ResponseHelper.error(403, 'Token is invalid'));
    }
}