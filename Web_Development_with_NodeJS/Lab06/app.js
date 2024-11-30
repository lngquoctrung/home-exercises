// * =====   MODULES   =====
const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');
const flash = require('connect-flash');
const cookieParser = require('cookie-parser');
require('dotenv').config();

const loginAuth = require('./middlewares/authentication/loginAuth');
const connectDB = require('./config/database');
const fileLoader = require('./middlewares/loader/fileLoader');


// * ===== ENVIRONMENTAL VARIABLES   =====
const SERVER_HOST = process.env.SERVER_HOST;
const SERVER_PORT = process.env.SERVER_PORT;
const MONGO_URL = process.env.MONGO_URL;
const SESSION_SECRET_KEY = process.env.SESSION_SECRET_KEY;

// * =====   APP   =====
const app = express();


// * =====   MIDDLEWARES   =====
// Handle with body parse
app.use(bodyParser.urlencoded({extended: true}));
// EJS view engine
app.set('view engine', 'ejs');
// Cookie
app.use(cookieParser());
// Session
app.use(session({
    secret: SESSION_SECRET_KEY, // Secret key use to decode session
    resave: false,              // Do not save session if it do not have any change
    saveUninitialized: false,
}));
// Send flash message between routes
app.use(flash());
app.use((req, res, next) => {
    res.locals.errorMsg = req.flash('error_msg');
    res.locals.successMsg = req.flash('success_msg');
    res.locals.notifications = req.flash('notifications');
    next();
});
// Check login authentication
app.use(loginAuth);


// * =====   ROUTERS   =====
app.use('/account', require('./routers/userRouter'));


// * ===== ROUTES   =====
// Home page
app.get('/', fileLoader, (req, res) => {
    res.render('index', {
        files: req.files,
        notifications: res.locals.notifications,
        name: req.session.name,
    });
});

// Login page
app.get('/login', (req, res) => {
    const formData = req.session.formData;
    delete req.session.formData;
    res.render('login', {
        ...formData,
        errorMsg: res.locals.errorMsg,
        notifications: res.locals.notifications
    });
})

// Register page
app.get('/register', (req, res) => {
    const formData = req.session.formData;
    delete req.session.formData;
    res.render('register', {
        ...formData,
        errorMsg: res.locals.errorMsg,
        notifications: res.locals.notifications
    });
})


// * =====   START SERVER   =====
const main = async () => {
    console.clear();
    // Connect to database
    await connectDB(MONGO_URL);
    app.listen(SERVER_PORT, () => {
        console.log(`The server is running on http://${SERVER_HOST}:${SERVER_PORT}`);
    })
}

main();