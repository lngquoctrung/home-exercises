const express = require('express');
const socketIo = require('socket.io');
const bodyParser = require('body-parser');
const session = require('express-session');
const cookieParser = require('cookie-parser');
const flash = require('connect-flash');
const passport = require('passport');
const dotenv = require('dotenv');
const connectDB = require('./config/database');
const authentication = require('./middlewares/authentication');
dotenv.config();
require('./config/passport');


// * ------- ENVIRONMENT VARIABLES -------
const serverHost = process.env.SERVER_HOST;
const serverPort = process.env.SERVER_PORT;
// Rise error if missing configuration
if(!serverHost || !serverPort){
    console.log('Internal server error: missing configuration');
    process.exit(1);
}


// * ------- INITIALIZE THE SERVER -------
const app = express();
app.set('view engine', 'ejs');


// * ------- MIDDLEWARES -------
app.use(bodyParser.urlencoded({ extended: true }));
app.use(cookieParser());
app.use(session({
    secret: process.env.SESSION_KEY,
    resave: false,
    saveUninitialized: false,
    cookie: {
        httpOnly: false,
        maxAge: 24 * 60 * 1000, // 24h
    }
}));
app.use(flash());
app.use((req, res, next) => {
    res.locals.errors = req.flash("errors");
    res.locals.formData = req.flash("formData")[0];
    next();
});
app.use(passport.initialize());
app.use(passport.session());
app.use(authentication);


// * ------- ROUTERS -------
app.use('/auth', require('./routers/userRouter'));


// * ------- ROUTES -------
app.get('/', (req, res) => {
    res.render('index');
});

app.get('/chat', (req, res) => {
    res.render('chat');
});

app.get('/login', (req, res) => {
    const isShowErr = res.locals.errors.length > 0;
    res.render('login', {
        isShowErr: isShowErr,
        errorMsg: res.locals.errors[0]?.msg || "",
        ...res.locals.formData
    });
});

app.get('/register', (req, res) => {
    const isShowErr = res.locals.errors.length > 0;
    res.render('register', {
        isShowErr: isShowErr,
        errorMsg: res.locals.errors[0]?.msg || "",
        ...res.locals.formData
    });
});


// * ------- START SERVER -------
const server = app.listen(serverPort, serverHost, async () => {
    console.clear();
    await connectDB();
    console.log(`The server is running on http://${serverHost}:${serverPort}`);
}).on('error', (error) => {
    console.log('Error occurred: ', error);
});