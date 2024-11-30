const success = {
	OK: 200,
	CREATED: 201,
};

const clientError = {
	BAD_REQUEST: 400,
	UNAUTHORIZED: 401,
	FORBIDDEN: 403,
	NOT_FOUND: 404,
	METHOD_NOT_ALLOWED: 405,
};

const serverError = {
	INTERNAL_SERVER_ERROR: 500,
};

module.exports = { success, clientError, serverError };
