# Cross-Site Scripting
A sample website with the XSS vulnerability.

## Execution
```bash
docker compose up -d
```

The website runs on http://localhost:8080.

Try entering malicious
`script` and `style` tags into the comments.

To connect to the database from command-line, use the following:
```bash
docker run --rm -it --network <network> mysql mysql -hdatabase -uroot -p
```

# Made with ❤ by [Param](https://www.paramsid.com).