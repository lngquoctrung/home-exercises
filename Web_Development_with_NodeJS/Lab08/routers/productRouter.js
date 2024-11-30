const express = require('express');
const productController = require('../controllers/productController');
const productValidate = require('../middlewares/validator/productValidate');
const validator = require('../middlewares/validator');
const authenticator = require('../middlewares/authenticator');
const uploader = require('../middlewares/uploader');
const router = express.Router();


router.get('/', productController.getAllProducts);
router.post('/', authenticator, 
                uploader, 
                productValidate.createProduct, 
                validator, 
                productController.createProduct
);

router.get('/:id', productController.getProductById);
router.put('/:id', authenticator,
                    uploader,
                    productValidate.updateProduct,
                    validator,
                    productController.updateProduct
);
router.delete('/:id', authenticator,
                    productController.deleteProduct
);
                 

module.exports = router;