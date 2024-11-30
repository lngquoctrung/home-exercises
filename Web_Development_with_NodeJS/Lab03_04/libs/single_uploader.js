const multer = require('multer');
const uuid = require('short-uuid');
const path = require('path');
const uploaderConfig = require('./uploader_config');

// Sử dụng middleware multer để xử lý upload file
const uploader = multer({
	storage: uploaderConfig.storgare,
	// Chỉ cho phép up file ảnh
	fileFilter: uploaderConfig.fileFilter('image/'),
	// Giới hạn kích thước tối đa của file được up
	limits: {
		fileSize: uploaderConfig.maxFileSize,
	},
});

// Middleware dùng để xác thực các thông tin trước khi thêm sản phẩm
module.exports = (req, res, next) => {
	const upload = uploader.single('image');
	upload(req, res, (err) => {
		const product = req.body;
		const file = req.file;
		if (product.name === '') {
			res.render('add', {
				isError: true,
				errMsg: 'Vui lòng nhập tên sản phẩm',
			});
		} else if (product.price === '') {
			res.render('add', {
				isError: true,
				errMsg: 'Vui lòng nhập giá sản phẩm',
				name: product.name,
			});
		} else if (err instanceof multer.MulterError) {
			// Trường hợp error là thuộc đối tượng MulterError
			// Lỗi này xuất hiện do các `limits` được định nghĩa
			res.render('add', {
				isError: true,
				errMsg: 'Kích thước ảnh không được vượt quá 5 MB',
				name: product.name,
				price: product.price,
			});
		} else if (!file) {
			// Lỗi này thuộc lỗi bên trong hàm callback của fileFilter trả về
			if (err) {
				res.render('add', {
					isError: true,
					errMsg: 'Chỉ hỗ trợ upload file ảnh',
					name: product.name,
					price: product.price,
				});
			} else {
				res.render('add', {
					isError: true,
					errMsg: 'Vui lòng upload ảnh sản phẩm',
					name: product.name,
					price: product.price,
				});
			}
		} else {
			const newProduct = {
				id: uuid.generate(),
				name: product.name,
				price: product.price,
				imgPath: path.join('..', 'uploads', file.filename),
				desc: product.desc,
			};
			// Gửi dữ liệu đến middleware tiếp theo
			res.product = newProduct;
			next();
		}
	});
};
