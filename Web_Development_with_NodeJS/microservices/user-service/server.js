const express = require('express');
const app = express();
app.use(express.json());

// Health check endpoint
app.get('/health', (req, res) => {
    res.status(200).json({ status: 'ok' });
});

const users = [
    { email: 'user@example.com', password: 'password123' }
];

app.get('/api/users', (req, res) => {
    const { email } = req.query;
    const user = users.find(u => u.email === email);
    if (user) {
        res.json(user);
    } else {
        res.status(404).json({ message: 'User not found' });
    }
});

app.listen(3002, () => {
    console.log('User service running on port 3002');
});
