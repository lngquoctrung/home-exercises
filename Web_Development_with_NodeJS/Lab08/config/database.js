const mongoose = require('mongoose');
require('dotenv').config();

// * === Biến môi trường ===
const MONGO_HOST = process.env.MONGO_HOST ?? 'localhost';
const MONGO_PORT = process.env.MONGO_PORT ?? 27017;
const MONGO_DBNAME = process.env.MONGO_DBNAME ?? 'api';


// * === Kết nối database ===
const connectDB = async () => {
    try{
        await mongoose.connect(`mongodb://${MONGO_HOST}:${MONGO_PORT}/${MONGO_DBNAME}`);
        console.log('Connected to database');
    }
    catch(error){
        console.error(`Something went wrong.\nError: ${error}`);
    }
}

module.exports = connectDB;