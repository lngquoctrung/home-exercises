const express = require('express');
const orderController = require('../controllers/orderController');
const authenticator = require('../middlewares/authenticator');
const orderValidate = require('../middlewares/validator/orderValidate');
const validator = require('../middlewares/validator');

const router = express.Router();

router.get('/', authenticator, orderController.getAllOrders);
router.post('/', authenticator, orderController.createOrder);
// orderValidate.createOrder, validator, 
module.exports = router;