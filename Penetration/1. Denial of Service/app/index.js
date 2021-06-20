const express = require('express');

const PORT = process.env.PORT ?? 5000;
const DEATH_LIMIT = process.env.DEATH_LIMIT ?? 100;

let connectionCount = 0;

const app = express();

app.set('view engine', 'ejs');

app.route('/*')
.all((req, res) => {
	connectionCount++;

	if (connectionCount > DEATH_LIMIT) {
		process.stderr.write(`Too many concurrent requests; Server crashed.`);
		process.exit(1);
	}

	res.render('index', { time: new Date().toUTCString() });
	setTimeout(() => connectionCount--, 1000);
});

app.listen(PORT, () => console.log(`App running on port ${PORT}.`));