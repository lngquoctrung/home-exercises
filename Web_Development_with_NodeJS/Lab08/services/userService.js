const User = require('../models/user');

/**
 * User service
 * @class UserService
 */
class UserService {
    /**
     * Hàm dùng để lấy thông tin người dùng thông qua filter
     * @param {Object} filter - Thông tin dùng để tìm kiếm
     * @returns {Object|undefined} user - Thông tin người dùng hoặc undefined nếu không tìm thấy
     * @throws {Error} - Lỗi khi truy vấn database
     */
    static getUser = async (filter) => {
        try{
            const user = await User.findOne(filter)
            if(user) return user;
            return;
        }
        catch(error){
            throw error;
        }
    }

    /**
     * Hàm dùng để tạo một user mới
     * @param {Object} user - Object chứa thông tin user
     * @returns {Object} newUser - Thông tin người dùng vừa được thêm vào database
     * @throws {Error} - Lỗi trong quá trình tạo user
     */
    static createUser = async (user) => {
        try{
            const newUser = new User(user);
            await newUser.save();
            return newUser;
        }
        catch(error){
            throw error;
        }
    }
    static deleteUser = async (filter) => {

    }
    static updateUser = async (filter, update) => {
        try{
            const updatedUser = User.updateOne(filter, update);
            return updatedUser;
        }
        catch(error){
            throw error;
        }
    }
}

module.exports = UserService;