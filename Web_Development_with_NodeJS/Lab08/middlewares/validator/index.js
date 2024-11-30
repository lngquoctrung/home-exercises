const { validationResult } = require('express-validator');
const ResponseHelper = require('../../helpers/responseHelper');
const fs = require('fs');

// Middleware kiểm tra dữ liệu có vi phạm các ràng buộc không?
module.exports = (req, res, next) => {
    const errors = validationResult(req);
    if(!errors.isEmpty()){
        if(req?.file){
            fs.unlinkSync(req.file.path);
        }
        return res
            .status(400)
            .json(ResponseHelper.error(
                400, 
                errors.array()[0].msg
            ));
    }
    else return next();
}