# Denial of Service (DoS)
Destroying a weak web server by flooding
it with HTTP requests.

## Execution
```bash
docker compose up -d

# Flood the server
python pyflooder.py localhost 8080 5000
```

The website runs on http://localhost:8080.

# Made with ❤ by [Param](https://www.paramsid.com).