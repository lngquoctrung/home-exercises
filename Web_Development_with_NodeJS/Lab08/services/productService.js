const Product = require('../models/product');

class ProductService{
    static getAll = async () => {
        try{
            return await Product.find({}).select('-__v');
        }
        catch(error){
            throw error;
        }
    }

    static createProduct = async (product) => {
        try{
            const newProduct = new Product(product);
            await newProduct.save();
            return product;
        }
        catch(error){
            console.log(error);
            throw error;
        }
    }

    static getProduct = async (filter) => {
        try{
            const product = await Product
                                    .findById(filter)
                                    .select('-__v');
            if(product) return product;
            return;
        }
        catch(error){
            throw error;
        }
    }

    static updateProduct = async (filter, update) => {
        try{
            const product = await Product
                                    .findByIdAndUpdate(filter, update, { new: true })
                                    .select('-__v');
            if(product) return product;
            return;
        }
        catch(error){
            throw error;
        }
    }

    static deleteProduct = async (filter) => {
        try{
            const product = await Product.findOneAndDelete(filter);
            if(product) return product;
            return;
        }
        catch(error){
            throw error;
        }
    }
}

module.exports = ProductService;