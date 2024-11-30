// * =====   MODULES   =====
const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');
const flash = require('connect-flash');
const validate = require('./middlewares/validate');
const userValidator = require('./middlewares/userValidator');
require('dotenv').config();
const userRouter = require('./routers/userRouter');
const httpStatusCodes = require('./utils/httpStatusCodes');



// * =====   ENVIRONMENT VARIABLES   =====
const SERVER_PORT = process.env.SERVER_PORT;
const SERVER_HOSTNAME = process.env.SERVER_HOSTNAME;
if (!SERVER_PORT || !SERVER_HOSTNAME) {
	console.error('Invalid hostname or port');
	process.exit(1);
}



// * =====   APP INITIALIZATION   =====
const app = express();
// Middlware set EJS view engine
app.set('view engine', 'ejs');
// Middleware handle with body parse
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
// Middleware set session
app.use(
	session({
		secret: process.env.SESSION_SECRET_KEY, // Secret key use to decode session
		resave: false, // Do not save session if it does not have any change
		saveUninitialized: false, // Do not save uninitialized sessions
	})
);
// Middleware use to send message between router
app.use(flash());



// * =====   ROUTERS   =====
// Home page
app.get('/', userRouter.getAllUsers, (req, res) => {
	const users = res.data;
	const message = req.flash('success')[0]; // Lấy message đầu tiên
	res.status(httpStatusCodes.success.OK).render('index', { 
		users: users,
		message: message
	 });
});
// Add page
app.get('/add', (req, res) => {
	res.status(httpStatusCodes.success.OK).render('add');
});

// Post router of add page
app.post('/add', userValidator.createUser, validate, userRouter.addUser, (req, res) => {
	const addedUser = res.addedUser;
	req.flash('success', `Đã thêm người dùng ${addedUser.fullname} thành công`);
    res.redirect('/');
});

// Profile page
app.get('/profile/:id', userRouter.getUserById, (req, res) => {
	const user = res.data;
	res.status(httpStatusCodes.success.OK).render('profile', { user });
});

//Update router
app.put('/update/:id', userValidator.createUser, validate, userRouter.updateUser, (req, res) => {
    const updatedUser = res.updatedUser;
    if (updatedUser) {
        res.status(httpStatusCodes.success.OK).json({
            status: httpStatusCodes.success.OK,
            message: 'Cập nhật thành công',
            data: updatedUser
        });
    }
});


// Delete router
app.delete('/delete/:id', userRouter.deleteUser, (req, res) => {
	const deletedUser = res.deletedUser;
	req.res.status(httpStatusCodes.success.OK).json({
		status: httpStatusCodes.success.OK,
		message: 'Deleted successfully',
		data: deletedUser,
	});
});

// 404 page
app.use((req, res) => {
	res.status(httpStatusCodes.clientError.NOT_FOUND).render('error');
});



// * =====   RUN SERVER   =====
app.listen(SERVER_PORT, SERVER_HOSTNAME, () => {
	console.log('-'.repeat(30));
	console.log(`The database is running on ${process.env.API_URL}`);
	console.log('-'.repeat(30));
	console.log(
		`Server is running on http://${SERVER_HOSTNAME}:${SERVER_PORT}`
	);
});
