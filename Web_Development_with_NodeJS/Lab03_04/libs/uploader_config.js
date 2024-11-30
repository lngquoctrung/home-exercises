const multer = require('multer');
const path = require('path');

// Xác định đường dẫn đích để lưu file
function setDestinationPath(destination) {
	return (req, file, callback) => {
		callback(null, destination);
	};
}

// Thay đổi tên file nếu upload thành công. Format tên file mới: `Tên file cũ-thời gian up.Định dạng file`
function changeFileName(req, file, callback) {
	const fileName = file.originalname;
	const newFileName = `${fileName.substring(
		0,
		fileName.indexOf('.')
	)}-${Date.now()}${path.extname(fileName)}`;
	callback(null, newFileName);
}

// Kiểm tra những file nào được phép lưu
function fileFilter(mimetype) {
	return (req, file, callback) => {
		if (file.mimetype.startsWith(mimetype)) callback(null, true);
		// Tham số đầu tiên của hàm callback sẽ là Object Error
		else callback(new Error('Minetype is invalid'), false);
	};
}

// File có kích thước tối đa 5 MB
const maxFileSize = 5000000;
// Đường dẫn đích để lưu file
const destinationDir = 'uploads';

// Cấu hình các option Disk Storage cho module multer
const storgare = multer.diskStorage({
	destination: setDestinationPath(destinationDir),
	filename: changeFileName,
});

module.exports = { storgare, fileFilter, destinationDir, maxFileSize };
