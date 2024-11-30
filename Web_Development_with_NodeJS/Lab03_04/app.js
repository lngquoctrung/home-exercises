/*
	Email: admin@gmail.com
	Pass: 12345
*/

const express = require('express');
const cookieParse = require('cookie-parser');
const expressSession = require('express-session');
const bodyParser = require('body-parser');
const rateLimit = require('express-rate-limit');
require('dotenv').config();

// Sử dụng middleware để xác thực người dùng đã đăng nhập hay chưa
const loginAuth = require('./libs/login_auth');
// Sử dụng middleware để lấy được file
const uploaderSingle = require('./libs/single_uploader');
// Middleware kiểm tra thông tin sản phẩm trước khi update
const updateProduct = require('./libs/update_product');

// Module express-rate-limit
// Module giới hạn số lượng request mỗi địa chỉ IP gửi đến server 
//   trong một thời gian nhất định.
const limiter = rateLimit({
	windowMs: 3 * 60 * 1000, // 15 phút
	limit: 100, // Giới hạn một IP chỉ được gửi tối đa 100 request trong 3p
	statusCode: 429,
	message: "Vui lòng quay lại sau",
});

// Cổng chạy server
const port = process.env.PORT;
console.clear(); // Clear terminal

// Khởi tạo server
const app = express();
// Thiết lập View Engine EJS
app.set('view engine', 'ejs');

// ========== Middleware ==========
// Middleware dùng để parse body
app.use(bodyParser.urlencoded({ extended: false }));

// Middleware sử dụng cookie
app.use(cookieParse());

// Middleware sử dụng session
app.use(
	expressSession({
		secret: 'secret_key', // Chuỗi bí mật dùng để ký session ID cookie
		resave: false, // Buộc session được lưu lại ngay, ngay cả khi không có thay đổi
		saveUninitialized: true, // Buộc lưu một session chưa được khởi tạo
	})
);

app.use(limiter);

// Middleware yêu cầu người dùng phải đăng nhập trước
//   khi thực hiện các tác vụ khác
app.use(loginAuth.authenticationCheck);

// Middleware khai báo folder uploads chứa tập tin tĩnh
app.use('/uploads', express.static('./uploads'));

// ========== Routing ==========
// Truy cập vào trang chủ
let productList = new Map();

app.get('/', (req, res) => {
	let message = req.session.message;
    req.session.message = null; // Xóa message ngay sau khi lấy ra
	res.render('index', { 
		productList: productList, 
		message: message
	});
});

// Trang login
app.get('/login', (req, res) => {
	res.render('login');
});

// Đăng nhập bằng login form
/*
    Middleware `formValidation` kiểm tra các input hợp lệ hay không.
    Middleware `userAuthentication` kiểm tra tài khoản hợp lệ hay không
*/
app.post(
	'/login',
	loginAuth.formValidation,
	loginAuth.userAuthentication,
	(req, res) => {
		res.redirect('/');
	}
);

// Trang thêm sản phẩm
app.get('/add', (req, res) => {
	res.render('add');
});

// Thêm sản phẩm
app.post('/add', uploaderSingle, (req, res) => {
	// Nếu bước nhập sản phẩm hợp lệ thì dữ liệu được gửi đến middleware tiếp theo
	const product = res.product;
	// Thêm sản phẩm vào danh sách sản phẩm
	productList.set(product.id, product);
	// Thêm thông báo vào session
    req.session.message = 'Sản phẩm đã được thêm thành công!';
	res.redirect('/');
});

// Chỉnh sửa sản phẩm
app.get('/edit/:id', (req, res) => {
	const id = req.params.id;
	const product = productList.get(id);
	if(product){
		res.render('edit', {
			id: id,
			oldName: product.name,
			oldPrice: product.price,
			oldImgPath: product.imgPath,
			oldDesc: product.desc,
			name: product.name,
			price: product.price,
			imgPath: product.imgPath,
			desc: product.desc,
		});
	} else{
		res.render('error', { title: '404', message: 'Sản phẩm không tồn tại' });
	}
});

// Chỉnh sửa sản phẩm
app.post('/edit/:id', updateProduct(productList), (req, res) => {
	const newUpdated = res.product;
	productList.set(req.params.id, newUpdated);
	req.session.message = 'Sản phẩm đã được cập nhật thành công!';
	res.redirect('/');
});

// Xoá sản phẩm
app.post('/delete', (req, res) => {
	const {id} = req.body;
	if(productList.has(id)){
		productList.delete(id);
		res.json({ success: true, message: 'Sản phẩm đã được xóa thành công!' });
	}
	else{
		res.status(404).json({ success: false, message: 'Không tìm thấy sản phẩm!' });
	}
});

// Trang chi tiết sản phẩm
app.get('/:id', (req, res) => {
	// Kiểm tra id có tồn tại hay không
	const id = req.params.id;
	const product = productList.get(id);
	if(product){
		res.render('product', {
			name: product.name,
			price: product.price,
			imgPath: product.imgPath,
			desc: product.desc,
		});
	} else{
		res.render('error', { title: '404', message: 'Sản phẩm không tồn tại' });
	}
});

// Dẫn đến trang 404 khi đường dẫn không hợp lệ
app.use((req, res) => {
	res.render('error', { title: '404', message: 'Page not found' });
});

// Chạy server
app.listen(port, () =>
	console.log(`Server is running on http://localhost:${port}`)
);
