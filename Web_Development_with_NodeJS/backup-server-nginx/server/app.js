const express = require('express');
const redis = require('redis');
const os = require('os');

const app = express();
app.use(express.json());

const redisClient = redis.createClient({
    url: 'redis://redis:6379',
});

app.set('view engine', 'ejs');

app.get('/', async (req, res) => {
    try{
        let counter = await redisClient.get('counter');
        if(!counter){
            await redisClient.set('counter', 0);
            counter = await redisClient.get('counter');
        }
        counter++;
        await redisClient.set('counter', counter);
        res.render('index', {
            device: os.hostname(),
            counter: counter
        });
    }
    catch(error){
        console.error('Internal Server Error');
    }
});

app.get('/health', (req, res) => {
    res.status(200).json({
        status: 'Health'
    });
})

app.listen(5000, () => {
    console.clear();

    redisClient.connect().catch(console.error);

    redisClient.on('connect', () => {
        console.log('Connected to Redis');
    });

    redisClient.on('error', (error) => {
        console.error('Redis error: ', error);
    });

    console.log('The server is running on http://localhost:5000');
});