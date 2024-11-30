const multer = require('multer');
const path = require('path');

const storage = multer.diskStorage({
    destination: (req, file, callback) => {
        callback(null, './temp');      // Lưu vào thư mục tạm thời
    },
    filename: (req, file, callback) => {
        callback(null, Date.now() + path.extname(file.originalname));
    }
});

const upload = multer({
    storage,
    limits: { fileSize: 5 * 1000000}, // 5MB 
    fileFilter: (req, file, callback) => {
        if(!file.mimetype.startsWith('image/')){
            callback(new Error('File is invalid', false))
        }
        callback(null, true);
    }
});


module.exports = upload;