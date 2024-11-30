const UserService = require('../services/userService');
const cookieConfig = require('../config/cookieConfig');

// * ------- LOGIN -------
const login = (req, res) => {
    req.session.email = 'abc@gmail.com';
    return res.redirect('/');
}


// * ------- REGISTER -------
const register = (req, res) => {
    // Session
    if(!req.body.remember){
        req.session.email = req.body.email;
        
    }
    // JWT
    else{
    }
    // Save data to database
    
    return res.redirect('/');
}

// * ------- GOOGLE -------
const google = (req, res) => {
    // `req` stored user, newAccessToken and newRefreshToken from previous middleware
    res.cookie('accessToken', req.user.newAccessToken, cookieConfig.accessToken);
    res.cookie('refreshToken', req.user.newRefreshToken, cookieConfig.refreshToken);
    return res.redirect('/');
}

const logout = async (req, res) => {
    // Clear user data into session
    if(req.session.user) req.session.destroy();
    // Remove refresh token
    if(req.cookies.accessToken){
        res.clearCookie('accessToken');
        res.clearCookie('refreshToken');
        // Clear refresh token in database
        await UserService.update({ email: req.email }, { refreshToken: ''});
    }
    return res.json({
        success: true,
        msg: 'Logout successfully'
    });
}

module.exports = { login, register, google, logout }