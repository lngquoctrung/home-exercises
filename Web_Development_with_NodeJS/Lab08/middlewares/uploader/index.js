const multer = require('multer');
const upload = require('./upload');
const ResponseHelper = require('../../helpers/responseHelper');
const fs = require('fs').promises;

module.exports = async (req, res, next) => {
    // Khởi tạo nếu 2 thư mục chưa tồn tại
    try{
        await fs.mkdir('uploads', { recursive: true });
        await fs.mkdir('temp', { recursive: true });
    }
    catch(error){
        console.log(error);
    }

    return upload.single('image')(req, res, (error) => {
        if(error){
            if(error instanceof multer.MulterError && error.code === 'LIMIT_FILE_SIZE'){
                return res
                    .status(400)
                    .json(ResponseHelper.error(400, 'File too large. Maximum size is 5MB'));
            }
            else{
                return res
                    .status(400)
                    .json(ResponseHelper.error(400, error.message));
            }
        }
        else if(!req.file){
            return res
                .status(400)
                .json(ResponseHelper.error(400, 'Please upload the image of product'));
        }
        else {
            return next();
        }
    });
}