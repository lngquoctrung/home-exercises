const ProductService = require('../services/productService');
const ResponseHelper = require("../helpers/responseHelper");
const path = require('path');
const fs = require('fs').promises;

const getAllProducts = async (req, res) => {
    try{
        const products = await ProductService.getAll();
        if(products){
            return res
                .status(200)
                .json(ResponseHelper.success(200, 'Fetched successfully', products))
        }
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const createProduct = async (req, res) => {
    try{
        // Thay đổi ảnh từ thư mục temp qua uploads
        const targetFilePath = path.join('uploads', req.file.filename);
        await fs.rename(req.file.path, targetFilePath);
        // Tách đường dẫn ảnh
        const url = `http://${process.env.SERVER_HOST}:${process.env.SERVER_PORT}`;
        const imageUrl = `${url}/public/${req.file.filename}`;
        // Lưu dữ liệu vào database
        const product = req.body;
        product.imageUrl = imageUrl;
        const newProduct = await ProductService.createProduct(product);
        return res
            .status(201)
            .json(ResponseHelper.success(201, 'Added product successfully', newProduct));
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const getProductById = async (req, res) => {
    try{
        const idProduct = req.params.id;
        const product = await ProductService.getProduct({_id: idProduct});
        if(!product){
            return res
                .status(404)
                .json(ResponseHelper.success(404, 'Product does not exist'));
        }
        return res
            .status(200)
            .json(ResponseHelper.success(200, 'Successfully', product));
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const updateProduct = async (req, res) => {
    try{
        const idProduct = req.params.id;
        // Thay đổi ảnh từ thư mục temp qua uploads
        const targetFilePath = path.join('uploads', req.file.filename);
        await fs.rename(req.file.path, targetFilePath);
        // Tách đường dẫn ảnh
        const url = `http://${process.env.SERVER_HOST}:${process.env.SERVER_PORT}`;
        const imageUrl = `${url}/public/${req.file.filename}`;
        // Lưu dữ liệu vào database
        const product = req.body;
        product.imageUrl = imageUrl;
        const updatedProduct = await ProductService.updateProduct({ _id: idProduct }, product);
        if(!updatedProduct){
            return res
                .status(404)
                .json(ResponseHelper.success(404, 'Product does not exist'));
        }
        else{
            return res
                .status(200)
                .json(ResponseHelper.success(200, 'Update product successfully', updatedProduct));
        }
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const deleteProduct = async (req, res) => {
    try{
        const idProduct = req.params.id;
        const deletedProduct = await ProductService.deleteProduct({ _id: idProduct });
        if(!deletedProduct){
            return res
                .status(404)
                .json(ResponseHelper.success(404, 'Product does not exist'));
        }
        else{
            return res
                .status(200)
                .json(ResponseHelper.success(200, 'Delete product successfully', deletedProduct));
        }
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

module.exports = { getAllProducts, createProduct, getProductById, updateProduct, deleteProduct };