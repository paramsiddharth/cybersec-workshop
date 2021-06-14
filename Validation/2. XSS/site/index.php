<?php
	function get_comments($db) {
		$output = $db->query('SELECT * FROM comments');

		if ($output->num_rows > 0) {
			global $comments;
			$comments = [];
			while ($comment = $output->fetch_assoc()) {
				array_push($comments, [
					'comment' => $comment['comment'],
					'author' => $comment['author']
				]);
			}
		}
	}
?>

<?php
	$db = new mysqli($_ENV['DB_HOST'], $_ENV['DB_USER'], $_ENV['DB_PASS'], $_ENV['DB_NAME']);

	$db->query('CREATE TABLE IF NOT EXISTS comments (author VARCHAR(50), comment TEXT)');

	$output = $db->query('SELECT * FROM comments');

	if ($output->num_rows < 1) {
		$comments = [
			[
				'comment' => 'Never going to give you up...',
				'author' => 'Kabir'
			],
			[
				'comment' => 'The product was amazing! OMG!',
				'author' => 'Mukul'
			],
			[
				'comment' => 'Didn\'t like it that much.',
				'author' => 'Prachur'
			],
			[
				'comment' => 'Kind of OK OK.',
				'author' => 'Khushi'
			]
		];

		foreach ($comments as $comment) {
			$query = $db->prepare('INSERT INTO comments (author, comment) VALUES (?, ?)');
			$query->bind_param('ss', $comment['author'], $comment['comment']);
			$query->execute();
			$query->close();
		}
	
		$db->commit();
	}

	if (isset($_POST)) {
		if (isset($_POST['comment']) && isset($_POST['name']) && $_POST['comment'] <> '' && $_POST['name'] <> '') {
			$query = $db->prepare('INSERT INTO comments (author, comment) VALUES (?, ?)');
			$query->bind_param('ss', $_POST['name'], $_POST['comment']);
			$query->execute();
			$query->close();

			$db->commit();
		}
	}

	get_comments($db);
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
	<link rel="stylesheet" href="style.css">
	<title>Feedback</title>
</head>
<body>
	<header>
		<h1>Comments</h1>
		<form method="POST" class="form">
			<input type="text" name='comment' id='comment' placeholder="Comment">
			<input type="text" name='name' id='name' placeholder="Name">
			<button type='submit'>Post</button>
		</form>
	</header>

	<main>
		<?php foreach ($comments as $comment): ?>
		<div class="comment">
			<div class="comment-text">
				<?= $comment['comment'] ?>
			</div>
			<div class="author"><?= $comment['author'] ?></div>
		</div>
		<?php endforeach; ?>
	</main>

	<footer>
		<p>&copy; DabluDabluDablu <?= date('Y') ?></p>
	</footer>
</body>
</html>

<?php
	mysqli_close($db);
?>