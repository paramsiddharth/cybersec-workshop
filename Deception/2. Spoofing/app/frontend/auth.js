$(() => {
	$('#auth').on('click', async function(e) {
		e.preventDefault();
		$(this).addClass('d-none');
		$('#loader').removeClass('d-none');
		const resp = await fetch('/api', {
			method: 'POST',
			credentials: 'include',
			headers: {
				'Content-Type': 'application/json'
			},
			body: JSON.stringify({ password: $('#password').val() })
		});
		if (!resp.ok) {
			$(this).removeClass('d-none');
			$('#loader').addClass('d-none');
		} else {
			window.location.replace('./info');
		}
	});

	$('#logout').on('click', async function(e) {
		e.preventDefault();
		$(this).addClass('d-none');
		$('#loader-logout').removeClass('d-none');
		const resp = await fetch('/api', {
			method: 'DELETE'
		});
		if (resp.ok) {
			$(this).removeClass('d-none');
			$('#loader-logout').addClass('d-none');
			$('#loutmsg').removeClass('d-none');
		}
	});
});