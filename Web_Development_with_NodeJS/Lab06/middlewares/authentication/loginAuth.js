const userService = require('../../services/userService');
const cookieConfigs = require('../../config/cookieConfig');
const { accessTokenService, refreshTokenService } = require('../../services/tokenService');

module.exports = async (req, res, next) => {
    const publicRoutes = ['/login', '/register', '/account/login', '/account/register']

    // Avoid navigating through endless login pages 
    if(publicRoutes.includes(req.originalUrl)){
        return next();
    }
    else{
        // Check access token whether exist in cookie or not
        const accessToken = req.cookies?.accessToken;
        if(!accessToken){
            // TODO: Handle with refresh token
            const refreshToken = req.cookies?.refreshToken;
            if(!refreshToken){
                // Send error message to next middleware
                req.flash('notifications', 'Session expired');
                // Require login when refresh token expired
                return res.redirect('/login');
            }
            // Refresh token has not expired
            try{
                // TODO: Reissue access token based on refresh token
                // Get user information from refresh token
                const decode = refreshTokenService.verifyToken(refreshToken);
                // Get user information from database
                const response = await userService.getUser({name: decode.name});
                // Reissue access token based on user information
                if(!response.success || response.data.refreshToken !== refreshToken){
                    // Send error message to next middleware
                    req.flash('notifications', 'Session expired');
                    // Token is invalid during verification
                    return res.redirect('/login');
                }
                // Generate new access and refresh tokens
                const newAccessToken = accessTokenService.createToken({name: response.data.name});
                const newRefreshToken = refreshTokenService.createToken({name: response.data.name});
                // Update refresh token in database
                await userService.updateUser({name: decode.name}, 
                                                {$set: {refreshToken: newRefreshToken}});
                res.cookie('accessToken', newAccessToken, cookieConfigs.accessToken);
                res.cookie('refreshToken', newRefreshToken, cookieConfigs.refreshToken);
                // Store user information in session
                req.session.name = decode.name;
                return next();
            }
            catch(error){
                // Send error message to next middleware
                req.flash('notifications', 'Session expired');
                // Token is invalid during verification
                return res.redirect('/login');
            }
        }
        // Access token has not expired
        try{
            const decode = accessTokenService.verifyToken(accessToken);
            // Store user information in session
            req.session.name = decode.name;
            return next();
        }
        catch(error){
            // Send error message to next middleware
            req.flash('notifications', 'Session expired');
            // Token is invalid during verification
            return res.redirect('/login');
        }
    }
}