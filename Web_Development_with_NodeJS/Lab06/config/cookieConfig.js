const cookieConfigs = {
    accessToken: {
        httpOnly: true,
        maxAge: 5 * 60 * 1000, // 5 minutes
        path: '/',
    },

    refreshToken: {
        httpOnly: true,
        maxAge: 12 * 60 * 60 * 1000, // 12 hours
        path: '/',
    }
}

module.exports = cookieConfigs;