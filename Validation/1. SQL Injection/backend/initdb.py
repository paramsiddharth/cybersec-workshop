import pymysql

info = {
	'param': 'paasaao',
	'vivek': 'jiyarejiya',
	'chatur': 'iamclever123',
	'mukul': 'koibatnahin'
}

def initdb(db: pymysql.Connection):
	with db.cursor() as cur:
		cur.execute('''
			CREATE TABLE IF NOT EXISTS users (username VARCHAR(30) NOT NULL, password VARCHAR(30) NOT NULL);
		''')
	
		db.commit()

		for u, p in info.items():
			cur.execute(f'SELECT * from users WHERE username = "{u}"')
			records = cur.fetchall()

			if len(records) < 1:
				cur.execute(f'INSERT INTO users (username, password) VALUES ("{u}", "{p}")')
		
		db.commit()