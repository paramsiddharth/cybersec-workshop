const process = 'Processing order...';
const success = 'The item will be delivered to your doorstep. Thank you for shopping!';

window.addEventListener('load', () => {
	if (Object.fromEntries(new URLSearchParams(window.location.search).entries()).hasOwnProperty('premium')) {
		const premium = document.querySelector('a.nav-item.premium');
		const buy = document.querySelector('a.nav-item.buy');
		premium.style.display = 'block';
		buy.style.display = 'none';
		document.querySelectorAll('a.nav-item').forEach(e => e.href += '?premium');
	}

	const buy = document.getElementById('buy');
	if (buy != null) {
		buy.addEventListener('click', function(e) {
			const done = document.getElementById('done');
			this.style.display = 'none';
			done.textContent = process;
			done.style.display = 'block';
			setTimeout(() => done.textContent = success, 1000);
		});
	}
});