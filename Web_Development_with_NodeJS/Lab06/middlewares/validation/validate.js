const { validationResult } = require('express-validator');

module.exports = (req, res, next) => {
    const errors = validationResult(req);
    // Form valid or not
    if(!errors.isEmpty()){
        // Get error message
        const error = errors.array()[0];
        // Store form data to keep data when page reload
        req.session.formData = req.body;
        // Send error message to next middleware
        req.errorMsg = error.msg;
    }
    return next();
}