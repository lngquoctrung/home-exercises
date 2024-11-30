class ResponseHelper {
    constructor(success, status, message, data){
        this.success = success,
        this.status = status,
        this.message = message
        if(data)
            this.data = data;
    }

    static success(status = 200, message = 'Successfully', data){
        return new ResponseHelper(true, status, message, data);
    }

    static error(status = 400, message = 'Failed', error){
        const errRes = new ResponseHelper(false, status, message);
        if(error)
            errRes.error = error;
        return errRes;
    }
}

module.exports = ResponseHelper;