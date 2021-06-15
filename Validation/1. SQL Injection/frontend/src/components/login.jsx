import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { ToastContainer, toast } from 'react-toastify';
import 'react-toastify/dist/ReactToastify.css';
import Loader from 'react-loader-spinner';

import './login.css';
import { BACKEND } from '../config';
import { Redirect } from 'react-router-dom';

const Login = ({ token, setToken }) => {
	const [username, setUsername] = useState('');
	const [password, setPassword] = useState('');
	const [redirect, setRedirect] = useState(null);

	useEffect(async () => {
		document.title = 'Login - DabluDabluDablu';

		if (token == null || token === 'null') {
			setRedirect(false);
		} else {
			try {
				const resp = await axios.post(BACKEND, null, {
					headers: {
						'X-Auth-Token': token
					}
				});
				if (resp.data === 'HELLO') {
					setRedirect(true);
				} else
					setRedirect(false);
			} catch (e) {
				setToken(null);
				setRedirect(false);
			}
		}
	}, []);

	const login = async e => {
		e.preventDefault();
		try {
			const resp = await axios.post(BACKEND + 'login', {
				username,
				password
			});
			const { token } = resp.data;
			setToken(token);
		} catch (e) {
			toast.error('Invalid username/password!');
		}
	};

	if (redirect)
		return <Redirect to={'/'} />;

	if (redirect === null)
		return <><div id='form'>
			<h1>DabluDabluDablu</h1>
			<Loader type='Rings' />
		</div><ToastContainer /></>;

	return <><form id='form' onSubmit={e => e.preventDefault()}>
		<h1>DabluDabluDablu</h1>
		<div className='form-item'>
			<label htmlFor='username'>
				<div className='label'>Username:</div>
				<input tabIndex={1} id='username' type='text' value={username} onChange={e => setUsername(e.target.value)} />
			</label>
		</div>
		<div className='form-item'>
			<label htmlFor='password'>
				<div className='label'>Password:</div>
				<input tabIndex={2} id='password' type='password' value={password} onChange={e => setPassword(e.target.value)} />
			</label>
		</div>
		<button tabIndex={3} type='submit' id='login' onClick={login}>Login</button>
	</form><ToastContainer /></>;
};

export default Login;