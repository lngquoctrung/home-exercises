const axios = require('axios');
const httpStatusCodes = require('../utils/httpStatusCodes');

// * =====   AXIOS CONFIGURE   =====
const api = axios.create({
	baseURL: process.env.API_URL,
});

// * =====   GET LIST OF USERS   =====
const getAllUsers = async (req, res, next) => {
	try {
		const response = await api.get('/');
		const data = response.data;
		// Store the data to use in the next middleware
		res.data = data;
		next();
	} catch (error) {
		if (error.status === 404) {
			const config = error.config;
			console.error({
				typeError: error.name,
				status: error.status,
				method: config.method,
				url: new URL(config.url, config.baseURL).toString(),
				message: error.message,
			});
			// Returns an empty array when fetching data failed
			res.data = [];
		}
		next();
	}
};

// * =====   GET USER BY ID   =====
const getUserById = async (req, res, next) => {
	const id = req.params.id;
	try {
		const response = await api.get(`/${id}`);
		const user = response.data;
		res.data = user;
		next();
	} catch (error) {
		if (error.status === 404) {
			const config = error.config;
			console.error({
				typeError: error.name,
				status: error.status,
				method: config.method,
				url: new URL(config.url, config.baseURL).toString(),
				message: error.message,
			});
		}
		// Redirect to 404 page when the url is invalid
		res.status(httpStatusCodes.clientError.NOT_FOUND).render('error', {
			errorMessage: 'User information does not exist, please check again',
		});
	}
};

// * =====   ADD USER   =====
const addUser = async (req, res, next) => {
	const userInfo = req.body;
	try{
		const response = await api.post('/', userInfo);
		const addedUser = response.data;
		res.addedUser = addedUser;
		next();
	}
	catch(error){
		const config = error.config;
		console.error({
			typeError: error.name,
			status: error.status,
			method: config.method,
			url: new URL(config.url, config.baseURL).toString(),
			message: error.message,
		});
		next();
	}
}

// * =====   UPDATE USER   =====
const updateUser = async (req, res, next) => {
    const id = req.params.id; // Lấy id từ params
    const updateInfo = req.body;
    
    try {
        const response = await api.put(`/${id}`, {
            fullname: updateInfo.fullname,
            gender: updateInfo.gender,
            age: updateInfo.age,
            email: updateInfo.email
        });
        
        const updatedUser = response.data;
        res.updatedUser = updatedUser;
        next();
    } catch (error) {
        const config = error.config;
        console.error({
            typeError: error.name,
            status: error.status,
            method: config.method,
            url: new URL(config.url, config.baseURL).toString(),
            message: error.message,
        });
        
        // Nếu không tìm thấy user
        if (error.status === 404) {
            return res.status(httpStatusCodes.clientError.NOT_FOUND).json({
                status: httpStatusCodes.clientError.NOT_FOUND,
                message: 'Không tìm thấy người dùng',
            });
        }
        
        // Lỗi server khác
        res.status(httpStatusCodes.serverError.INTERNAL_SERVER).json({
            status: httpStatusCodes.serverError.INTERNAL_SERVER,
            message: 'Có lỗi xảy ra khi cập nhật người dùng',
        });
    }
};


// * =====   DELETE USER   =====
const deleteUser = async (req, res, next) => {
	const id = req.params.id;
	try {
		const response = await api.delete(`/${id}`);
		const deletedUser = response.data;
		res.deletedUser = deletedUser;
		next();
	} catch (error) {
		if (error.status === 404) {
			const config = error.config;
			console.error({
				typeError: error.name,
				status: error.status,
				method: config.method,
				url: config.url,
				message: error.message,
			});
		}
		// Redirect to 404 page when the url is invalid
		res.status(httpStatusCodes.clientError.NOT_FOUND).json({
			status: httpStatusCodes.clientError.NOT_FOUND,
			message: 'User does not exist, please check again',
		});
	}
};

module.exports = { getAllUsers, getUserById, addUser, updateUser, deleteUser };
