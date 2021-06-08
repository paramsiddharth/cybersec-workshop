import React from 'react';
import useLocalStorage from 'react-use-localstorage';
import { BrowserRouter as Router, Route, Switch, Redirect } from 'react-router-dom';

import Login from './components/login';
import Home from './components/home';

function App() {
	const [token, setToken] = useLocalStorage('appToken', null);

	return <Router >
		<Switch>
			<Route exact path='/login' component={() => <Login token={token} setToken={setToken} />} />
			<Route exact path='/' component={() => <Home token={token} setToken={setToken} />} />
			<Redirect to='/' />
		</Switch>
	</Router>;
}

export default App;