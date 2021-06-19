# Hash Cracking
Using a dictionary attack to crack common
passwords stored in the form of MD5 and
SHA-256 hashes.

## Execution
```bash
# Enter the database
sqlite3 file:users.db?mode=ro
```
```sql
# Get the account passwords (MD5)
.mode csv
.output passwords.txt
SELECT password FROM users;

# Get the wallet pins (SHA-256)
.output pins.txt
SELECT pin FROM wallets;

# Back to console
.exit
```
```bash
# Examine the hashes
#   MD5           SHA-256
cat passwords.txt pins.txt

# Use Hashcat to crack passwords
# (with common.txt as the dictionary)
hashcat -a 0 -m 0 -o "$(pwd)/passwords-cracked.txt" "$(pwd)/passwords.txt" "$(pwd)/common.txt"

# Repeat for wallet pins
hashcat -a 0 -m 1400 -o "$(pwd)/pins-cracked.txt" "$(pwd)/pins.txt" "$(pwd)/common.txt"

# Get the cracked strings
cat passwords-cracked.txt pins-cracked.txt | cut -d: -f2
```

# Made with ❤ by [Param](https://www.paramsid.com).