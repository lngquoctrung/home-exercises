const Order = require('../models/order');

module.exports = class OrderService {
    static getAll = async (filter) => {
        try{
            const orders = await Order.find(filter);
            return orders;
        }
        catch(error){
            throw error;
        }
    }

    static createOrder = async (order) => {
        try{
            const newOrder = new Order(order);
            await newOrder.save();
            return newOrder;
        }
        catch(error){
            throw error;
        }
    }
}