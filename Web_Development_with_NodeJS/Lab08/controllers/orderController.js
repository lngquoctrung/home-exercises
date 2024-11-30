const OrderService = require('../services/orderService');
const ResponseHelper = require('../helpers/responseHelper');
const UserService = require('../services/userService');

const getAllOrders = async (req, res) => {
    try{
        // Lấy id người dùng
        const user = await UserService.getUser({ email: req.email });
        // Lấy thông tin order bằng id người dùng
        const orders = await OrderService.getAll(user._id);
        return res
            .status(200)
            .json(ResponseHelper.success(200, 'Fetched data successfully', orders));
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const createOrder = async (req, res) => {
    try{
        // Lấy id người dùng
        const user = await UserService.getUser({ email: req.email });
        const newOrder = await OrderService.createOrder(req.body);
        return res
            .status(201)
            .json(ResponseHelper.success(201, 'Added order successfully', newOrder));
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const updateOrder = async (req, res) => {

}

module.exports = { getAllOrders, createOrder, updateOrder };