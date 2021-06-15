const ERROR_MSG = `
	<span class='text-danger'>Error retrieving records. Did you <a href='/'>authenticate</a> yourself?</span>
`;

$(async () => {
	let resp;
	try {
		resp = await fetch('/api');
	} catch (e) {
		return $('#loader').html(ERROR_MSG);
	}

	if (!resp.ok) {
		return $('#loader').html(ERROR_MSG);
	}

	let tasks = await resp.json();
	console.log(tasks);

	$('#loader-row').hide();

	tasks = tasks.map(task => `
		<div class='col-12 offset-md-4 col-md-4 mt-2 text-left p-4 bg-warning text-dark rounded-3'>
			<div class='h6 md-h4'>&bull; ${task.todo}</div class='h6 md-h4'>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Priority: ${task.priority}
		</div>
	`);

	const cont = $('#content');
	cont.html(cont.html() + tasks.join('\n'));
});