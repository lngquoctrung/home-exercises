const { accessTokenService, refreshTokenService } = require('../services/tokenService');
const userService = require('../services/userService');
const cookieConfigs = require('../config/cookieConfig');
const bcrypt = require('bcryptjs');


const login = async (req, res) => {
    // Check error message from previous middleware
    if(req.errorMsg) {
        // Send flash message to login page
        req.flash('error_msg', req.errorMsg);
        // Redirect to login page to display error message
        return res.redirect('/login');
    }

    // TODO: Check login information
    // Get form data to validate and save database
    const user = req.body;

    const response = await userService.getUser({name: user.name});

    if(!response.success){
        // Send flash message to register page
        req.flash('error_msg', 'Account does not exist');
        // Store form data to keep data when page reload
        req.session.formData = req.body;
        // Redirect to login page to display error message
        return res.redirect('/login');
    }
    else if(!await bcrypt.compare(user.pass, response.data.pass)){
        // Send flash message to register page
        req.flash('error_msg', 'Password is incorrect');
        // Store form data to keep data when page reload
        req.session.formData = req.body;
        // Redirect to login page to display error message
        return res.redirect('/login');
    }

    // Generate new access and refresh tokens
    const newAccessToken = accessTokenService.createToken({name: response.data.name});
    const newRefreshToken = refreshTokenService.createToken({name: response.data.name});
    
    // Update new reresh token to database
    await userService.updateUser({name: user.name}, 
                                {$set: {refreshToken: newRefreshToken}});

    // Send cookie to client
    res.cookie('accessToken', newAccessToken, cookieConfigs.accessToken);
    res.cookie('refreshToken', newRefreshToken, cookieConfigs.refreshToken);

    // Store user name to session
    req.session.name = user.name;
    // Form is valid then send notification to home page
    req.flash('notifications', 'Login successfully');
    return res.redirect('/');
}

const register = async (req, res) => {
    // Check error message from previous middleware
    if(req.errorMsg) {
        // Send flash message to register page
        req.flash('error_msg', req.errorMsg);
        // Redirect to login page to display error message
        return res.redirect('/register');
    }

    // Get form data to validate and save database
    const user = req.body;
    // Check user existed
    const response = await userService.getUser({name: user.name, 
                                            email: user.email});
    if(response.success){
        // Send flash message to register page
        req.flash('error_msg', 'Account existed');
        // Store form data to keep data when page reload
        req.session.formData = req.body;
        // Redirect to login page to display error message
        return res.redirect('/register');
    }

    // Create token
    const accessToken = accessTokenService.createToken({name: user.name});
    const refreshToken = refreshTokenService.createToken({name: user.name});
    // Send cookie to client
    res.cookie('accessToken', accessToken, cookieConfigs.accessToken);
    res.cookie('refreshToken', refreshToken, cookieConfigs.refreshToken);
    // TODO: Save user to database
    try{
        // Hash password
        const salt = await bcrypt.genSalt(parseInt(process.env.SALT_ROUNDS, 10));
        const hashedPass = await bcrypt.hash(user.pass, salt);
        user.pass = hashedPass;
        // Save user to database
        await userService.createUser({...user, refreshToken: refreshToken});
        // Store user name to session
        req.session.name = user.name;
        // Form is valid then send notification to home page
        req.flash('notifications', 'Register successfully');
        return res.redirect('/');
    }
    catch(error){
        console.log(error);
    }
}

const logout = async (req, res) => {
    try{
        // Remove cookie from client
        res.clearCookie('accessToken');
        res.clearCookie('refreshToken');
        // Remove token from database
        await userService.updateUser({name: req.session.name}, 
                                    {$set: {refreshToken: ''}});
        // Redirect to home page
        req.flash('notifications', 'Logout successfully');
        return res.redirect('/login');
    }
    catch(error){
        console.log(error);
    }
}

module.exports = { login, register, logout }