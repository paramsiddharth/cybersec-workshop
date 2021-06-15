const express = require('express');
const CORS = require('cors');

const PORT = process.env.PORT ?? '80';

const app = express();

app.use(CORS());

app.listen(PORT, () => console.log(`Listening on port ${PORT}.`));