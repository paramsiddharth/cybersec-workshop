# Spoofing
Feigning authentication using cookie-spoofing.

## Execution
```bash
docker compose up -d
```

The website runs on http://localhost:8080.

Navigate to a friend's PC who is authenticated
and try grabbing the `session` and `session.sig` cookies.

Copy them to your machine and add them as cookies
via the Application tab inside your browser's
debugging tools.

# Made with ❤ by [Param](https://www.paramsid.com).