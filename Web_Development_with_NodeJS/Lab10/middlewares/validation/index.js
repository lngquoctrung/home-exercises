const { validationResult } = require('express-validator');

module.exports = (req, res, next) => {
    // Validate form
    const errors = validationResult(req);
    if(!errors.isEmpty()){
        // Send error to display
        const authPath = req.originalUrl.split('/')[2];
        req.flash("errors", errors.array());
        req.flash("formData", req.body);
        return res.redirect(`/${authPath}`);
    }
    return next();
}