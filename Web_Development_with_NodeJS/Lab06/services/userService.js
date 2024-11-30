const User = require('../models/User');

/**
 * User service layer
 * @class UserService
 */
class UserService {
    /**
     * Create a new user
     * @param {Object} user - User information
     * @returns {Object} - The result of creating a new user 
     * @throws {Error} - If there is an error creating a new user
     */
    static createUser = async (user) => {
        try{
            const newUser = new User(user);
            await newUser.save();
            return {
                success: true,
                message: 'User is created successfully',
                data: newUser
            }
        }
        catch(error){
            throw error;
        } 
    }

    /**
     * Get a user by filter
     * @param {Object} filter - Filter to find the user
     * @returns {Object} - The result of getting a user
     * @returns {Object} - The result of getting a user
     * @throws {Error} - If there is an error getting a user
     */
    static getUser = async (filter) => {
        try{
            const user = await User.findOne(filter).select('-_id -__v');
            if(user){
                return {
                    success: true,
                    message: 'Success',
                    data: user
                }
            }
            else{
                return {
                    success: false,
                    message: 'Not found'
                }
            }
        }
        catch(error){
            throw error;
        }
    }

    /**
     * Update a user
     * @param {Object} filter - Filter to find the user
     * @param {Object} update - Update information
     * @returns {Object} - The result of updating a user
     * @throws {Error} - If there is an error updating a user
     */
    static updateUser = async (filter, update) => {
        try {
            const updatedUser = await User.findOneAndUpdate(filter, update);
        } catch(error) {
            console.error('Error updating user:', error);
            throw error;
        }
    }
}

module.exports = UserService;
