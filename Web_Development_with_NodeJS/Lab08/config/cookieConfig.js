module.exports = cookieConfigs = {
    accessCookie: {
        httpOnly: true,
        maxAge: 15 * 60 * 1000, // 15 phút
    },
    refreshCookie: {
        httpOnly: true,
        maxAge: 7 * 60 * 60 * 1000, // 7 tiếng
    }
}