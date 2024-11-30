const mongoose = require('mongoose');

const connectDB = async (url) => {
    try{
        // Connect to MongoDB
        await mongoose.connect(url);
        console.log('Connected to database successfully');
    }
    catch(error){
        console.error('Can not connect to database');
        process.exit(1);
    }
}

module.exports = connectDB;