const express = require('express')
const userController = require('../controllers/userController');
const userValidator = require('../middlewares/validation/userValidator');
const validate = require('../middlewares/validation/validate');

const router = express.Router();

router.post('/login', userValidator.login, validate, userController.login);
router.post('/register', userValidator.register, validate, userController.register);
router.get('/logout', userController.logout);

module.exports = router;