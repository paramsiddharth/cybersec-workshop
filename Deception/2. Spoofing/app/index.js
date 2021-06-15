const express = require('express');
const morgan = require('morgan');
const path = require('path');
const { statusCode } = require('statushttp');
const session = require('cookie-session');

const { cookieLife } = require('./config');

require('dotenv').config();
const PORT = process.env.PORT ?? '80';

const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(session({
	name: 'session',
	keys: [
		process.env.SECRET ?? 'dev'
	],
	maxAge: cookieLife
}));

app.use(morgan('dev'));
app.use('/', express.static(path.join(__dirname, 'frontend')));
app.use('/modules', express.static(path.join(__dirname, 'node_modules')));

app.route('/api')
.get((req, res) => {
	if (req.session && req.session?.user === 'admin') {
		return res.status(statusCode.OK).json([
			{ priority: 1, todo: 'Eat food.' },
			{ priority: 1, todo: 'Go for a walk.' },
			{ priority: 2, todo: 'Make donations.' },
			{ priority: 3, todo: 'Use computer.' }
		]);
	}
	return res.status(statusCode.UNAUTHORIZED).end();
})
.post((req, res) => {
	if (req.body?.password === (process.env.PASSWORD ?? 'devpass')) {
		req.session = {
			user: 'admin'
		};
		res.status(statusCode.ACCEPTED).end();
	}
	res.status(statusCode.FORBIDDEN).end();
})
.delete((req, res) => {
	req.session = null;
	res.status(statusCode.OK).end();
});

app.listen(PORT, () => console.log(`Listening on port ${PORT}.`));