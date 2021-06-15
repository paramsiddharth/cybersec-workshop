# Phishing
Using the Social-Engineer Toolkit (SET) to generate
a phising page.

## Execution

We will be using Ngrok for tunneling.
```bash
# Execute inside the host machine
ngrok http 8080
```

The following runs the CLI:
```bash
docker compose run --service-ports set
```

Follow the following sequence for inputting the options.
For the 6<sup>th</sup> input, paste your Ngrok URL
without the `http://` prefix.
```
y
1
2
3
1
<Your Ngrok URL without the http:// prefix>
2

```

The website runs on http://localhost:8080 and your
provided Ngrok URL, both on HTTP and HTTPS.

## Warning
Don't use your real credentials, especially
during a public demonstration.

# Made with ❤ by [Param](https://www.paramsid.com).