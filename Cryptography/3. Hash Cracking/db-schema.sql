CREATE TABLE users (username VARCHAR(30) PRIMARY KEY, password TEXT NOT NULL);
CREATE TABLE wallets (
    username VARCHAR(30),
    pin TEXT,
    FOREIGN KEY (username) REFERENCES users(username) ON DELETE CASCADE
);