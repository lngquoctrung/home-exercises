const express = require('express');
const axios = require('axios');
const app = express();
app.use(express.json());

// Health check endpoint
app.get('/health', (req, res) => {
    res.status(200).json({ status: 'ok' });
});

let products = [
    { id: 1, name: 'Product 1', price: 100 },
    { id: 2, name: 'Product 2', price: 200 }
];

// Middleware kiểm tra authentication
const checkAuth = async (req, res, next) => {
    if (req.method === 'POST') {
        try {
            // Gọi qua HAProxy thay vì trực tiếp
            const authResponse = await axios.get('http://haproxy/auth/check-auth', {
                headers: {
                    'Cookie': req.headers.cookie || ''
                }
            });
            next();
        } catch (error) {
            return res.status(403).json({ message: 'Authentication required' });
        }
    } else {
        next();
    }
};

app.get('/api/products', (req, res) => {
    res.json(products);
});

app.post('/api/products', checkAuth, (req, res) => {
    const newProduct = {
        id: products.length + 1,
        name: req.body.name,
        price: req.body.price
    };
    products.push(newProduct);
    res.status(201).json(newProduct);
});

app.listen(3001, () => {
    console.log('Product service running on port 3001');
});
