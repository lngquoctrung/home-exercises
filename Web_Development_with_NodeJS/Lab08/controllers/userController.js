const UserSevice = require("../services/userService");
const ResponseHelper = require("../helpers/responseHelper");
const cookieConfig = require('../config/cookieConfig');
const { accessTokenHelper, refreshTokenHelper } = require('../helpers/tokenHelper');

// * === Đăng nhập ===
const login = async (req, res) => {
    const user = req.body;
    try{
        // Kiểm tra user có tồn tại hay không?
        const existedUser = await UserSevice.getUser({email: user.email});
        if(!existedUser){
            return res
                .status(404)
                .json(ResponseHelper.error(404, "Account does not exist"));
        }
        // Kiểm tra mật khẩu
        else{
            const isMatched = await existedUser.comparePassword(user.password);
            if(!isMatched){
                return res
                    .status(400)
                    .json(ResponseHelper.error(400, "Incorrect password"));
            }
            else{
                // Tạo accessToken và refreshToken
                const accessToken = accessTokenHelper.sign({email: user.email});
                const refreshToken = refreshTokenHelper.sign({email: user.email});
                // Cập nhật lại refreshToken trong database
                await UserSevice.updateUser({email: user.email}, {refreshToken: refreshToken});
                // Lưu các token vào cookie
                res.cookie('accessToken', accessToken, cookieConfig.accessCookie);
                res.cookie('refreshToken', refreshToken, cookieConfig.refreshCookie);
                // Gửi phản hồi về phía client
                return res
                    .status(200)
                    .json(ResponseHelper.success(
                        200, 
                        'Login successfully',
                    ));
            }
        }
    }
    // Lỗi từ phía server
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
};


// * === Đăng ký ===
const register = async (req, res) => {
    // Đọc dữ liệu từ body
    const user = req.body;
    try {
        // Kiểm tra người dùng đã tồn tại hay chưa
        const existedUser = await UserSevice.getUser({ email: user.email });
        // Người dùng đã tồn tại
        if (existedUser) {
            return res
                .status(404)
                .json(ResponseHelper.error(404, "Account existed"));
        } 
        // Người dùng chưa tồn tại
        else {
            // Tạo accessToken và refreshToken
            const accessToken = accessTokenHelper.sign({email: user.email});
            const refreshToken = refreshTokenHelper.sign({email: user.email});
            // Lưu dữ liệu vào database
            const {username, email, password} = user;
            const newUser = await UserSevice.createUser({username, email, password, refreshToken});
            if(newUser){
                // Lưu các token vào cookie
                res.cookie('accessToken', accessToken, cookieConfig.accessCookie);
                res.cookie('refreshToken', refreshToken, cookieConfig.refreshCookie);
                // Gửi phản hồi về phía client
                return res
                    .status(201)
                    .json(ResponseHelper.success(
                        201, 
                        'Added successfully', 
                        {username: username, email: email}
                    ));
            }
        }
    } 
    // Lỗi từ phía database
    catch (error) {
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
};

const logout = async (req, res) => {
    try{
        res.clearCookie('accessToken');
        res.clearCookie('refreshToken');
        await UserSevice.updateUser({ email: req.email }, { refreshToken: '' });
        return res
            .status(200)
            .json(ResponseHelper.success(200, 'Logout successfully'));
    }
    catch(error){
        return res
            .status(500)
            .json(ResponseHelper.error(500, "Something went wrong", error));
    }
}

const refresh = async (req, res) => {
    try{
        const refreshToken = req.cookies.refreshToken;
        if(!refreshToken){
            return res
                .status(403)
                .json(ResponseHelper.error(403, 'Token has expired'));
        }
        else{
            const decode = refreshTokenHelper.verify(refreshToken);
            res.cookie('accessToken', accessTokenHelper.sign({ email: decode.email }));
            return res
                .status(200)
                .json(ResponseHelper.success(200, 'Refresh token successfully'));
        }
    }
    catch(error){
        return res
            .status(403)
            .json(ResponseHelper.error(403, 'Token is invalid'));
    }
}

module.exports = { login, register, logout, refresh };
