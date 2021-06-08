import sys, os
import pymysql
from flask import Flask, jsonify, request
from flask_cors import CORS
import hashlib

from initdb import initdb

tokens = []

def md5(s):
	return hashlib.md5(s.encode(encoding='utf-8'))

DB_URL = os.environ.get('DB_URL')
DB_USER = os.environ.get('DB_USER')
DB_PASS = os.environ.get('DB_PASS')
if any(map(lambda x: x is None, (DB_URL, DB_USER, DB_PASS))):
	print('Environment variables not found!', file=sys.stderr)
	sys.exit(1)

db = pymysql.connect(host=DB_URL, user=DB_USER, password=DB_PASS, database='users')
initdb(db)

PORT = os.environ.get('PORT', 3000)
app = Flask(__name__)
CORS(app)

@app.route('/login', methods=['POST'])
def main(*args, **kwargs):
	if request.json is None:
		return 'Only JSON allowed.', 400
	
	username = request.json.get('username')
	password = request.json.get('password')
	if username is None or password is None:
		return 'Username and password required!', 400
	
	with db.cursor() as cur:
		cur.execute(f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'")
		user = cur.fetchone()
		
		if user is None:
			return 'Invalid username or password!', 401

		token = f'{username}:{md5(username + password).hexdigest()}'
		if token not in tokens:
			tokens.append(token)
		
		return jsonify({
			'token': token
		})

@app.route('/', methods=['POST'])
def home(*args, **kwargs):
	token = request.headers.get('X-Auth-Token')
	if token not in tokens:
		return 'Invalid token!', 401
	
	return 'HELLO'

@app.route('/flush', methods=['POST'])
def flush(*args, **kwargs):
	token = request.headers.get('X-Auth-Token')
	if token in tokens:
		tokens.remove(token)
		return 'FLUSHED', 200
	
	return 'Invalid token!', 401

if __name__ == '__main__':
	app.run(host='0.0.0.0', port=PORT)