const express = require('express');
const session = require('express-session');
const cors = require('cors');
const { rateLimit } = require('express-rate-limit');
const connectDB = require('./config/database');
const bodyParse = require('body-parser');
const cookieParser = require('cookie-parser');
require('dotenv').config();

// * === Biến môi trường ===
const SERVER_PORT = process.env.SERVER_PORT ?? 5050;
const SERVER_HOST = process.env.SERVER_HOST ?? 'localhost';
const SESSION_SECRET_KEY = process.env.SESSION_SECRET_KEY;
// Kiểm tra các biến môi trường
if(!SERVER_PORT || !SERVER_HOST || !SESSION_SECRET_KEY){
    console.error('Configuration is missing');
    process.exit(1);
}

// * === Khởi tạo ứng dụng ===
const app = express();

// * === Middlewares ===
app.use(session({
    secret: SESSION_SECRET_KEY,     // Key để sign session ID cookie, bảo vệ và mã hoá session 
    saveUninitialized: false,       // Session chưa được mofify sẽ không được lưu
    resave: false,                  // Session sẽ không được lưu nếu không có thay đổi
}));
app.use(cors());
app.use(rateLimit({
    windowMs: 15 * 60 * 100,        // Thời gian giới hạn
    limit: 50,                      // Số lượng request tối đa có thể gửi trong khoảng 15p
    message: 'Too many request',    // Thông báo lượng request vượt quá quy định
}));
app.use(bodyParse.urlencoded({ 
    extended: true                  // Sử dụng thư viện `qs` để parse data (false thì sẽ dùng `querystring`)
}));
app.use(bodyParse.json());
app.use(cookieParser());


// * === Routers ===
app.use('/public', express.static('./uploads'));
app.use('/api/account', require('./routers/userRouter'));
app.use('/api/products', require('./routers/productRouter'));
app.use('/api/orders', require('./routers/orderRouter'));
app.use((req, res) => {
    res
        .status(404)
        .json({
            status: 404,
            message: 'Not found'
        })
})

// * === Chạy server ===s
app.listen(SERVER_PORT, SERVER_HOST, async () => {
    console.clear();
    await connectDB();
    console.log(`Server is running on http://${SERVER_HOST}:${SERVER_PORT}`);
})