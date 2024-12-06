const express = require('express');
const axios = require('axios');
const cookieParser = require('cookie-parser');

const app = express();
app.use(express.json());
app.use(cookieParser());

// Health check endpoint
app.get('/health', (req, res) => {
    res.status(200).json({ status: 'ok' });
});

app.get('/auth/check-auth', (req, res) => {
    const email = req.cookies.email;
    if (!email) {
        return res.status(403).json({ message: 'Not authenticated' });
    }
    res.json({ email });
});

app.post('/auth/login', async (req, res) => {
    const { email, password } = req.body;
    
    try {
        // Gọi qua HAProxy thay vì trực tiếp
        const response = await axios.get(`http://haproxy/api/users?email=${email}`);
        const user = response.data;
        
        if (user && user.password === password) {
            res.cookie('email', email, { httpOnly: true });
            res.json({ message: 'Login successful' });
        } else {
            res.status(401).json({ message: 'Invalid credentials' });
        }
    } catch (error) {
        res.status(500).json({ message: 'Error during login' });
    }
});

app.listen(3003, () => {
    console.log('Auth service running on port 3003');
});
