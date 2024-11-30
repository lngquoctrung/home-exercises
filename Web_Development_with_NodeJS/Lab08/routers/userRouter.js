const express = require('express');
const userController = require('../controllers/userController');
const userValidate = require('../middlewares/validator/userValidate');
const validator = require('../middlewares/validator');
const authenticator = require('../middlewares/authenticator');
const router = express.Router();

router.post('/login', userValidate.login, validator, userController.login);
router.post('/register', userValidate.register, validator, userController.register);
router.post('/logout', authenticator, userController.logout);
router.post('/refresh', userController.refresh);

module.exports = router;