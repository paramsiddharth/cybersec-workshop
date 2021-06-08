import React, { useEffect, useState } from 'react';
import { Redirect } from 'react-router-dom';
import Loader from 'react-loader-spinner';
import axios from 'axios';

import './home.css';
import { BACKEND } from '../config';

const Home = ({ token, setToken }) => {
	const [content, setContent] = useState(<Loader type='ThreeDots' style={{ textAlign: 'center' }} />);

	useEffect(async () => {
		document.title = 'Home - DabluDabluDablu';

		if (token == null || token === 'null') {
			setContent(<Redirect to='/login' />);
		} else {
			try {
				const resp = await axios.post(BACKEND, null, {
					headers: {
						'X-Auth-Token': token
					}
				});
				if (resp.data === 'HELLO') {
					setContent(<h2 style={{ textAlign: 'center' }}>Hello!</h2>);
				} else
					setContent(<Redirect to='/login' />);
			} catch (e) {
				setToken(null);
				setContent(<Redirect to='/login' />);
			}
		}
	}, []);

	if (token == null)
		return <Redirect to='../login' />;

	return <><div id='block'>
		<h1>DabluDabluDablu</h1>
		<div className='block-item'>
			{content}
		</div>
		<button tabIndex={0} id='logout' onClick={() => setToken(null)}>Logout</button>
	</div></>;
};

export default Home;