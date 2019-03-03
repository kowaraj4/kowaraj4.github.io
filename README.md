# shapkee

##  Run

### 1. Start the Backend to serve static files from ./public
```
[root@d777a1dfc437 build]# pwd
/src/shapkee/build
[root@d777a1dfc437 build]# ../node_modules/.bin/http-server .
```
This starts an http server listening on port 8080:
```
Starting up http-server, serving .
Available on:
  http://127.0.0.1:8080
  http://172.17.0.2:8080
```

### 2. Start the bundler
```
[root@d777a1dfc437 shapkee]# pwd
/src/shapkee
[root@d777a1dfc437 shapkee]# npm start
```

### 3. Run the webpack-dev-server
```
[root@d777a1dfc437 shapkee]# pwd
/src/shapkee
[root@d777a1dfc437 shapkee]# npm run server
```



## How To

### Change port number for webpack-dev-server

Modify `package.json`:
```
    "server": "webpack-dev-server --host 0.0.0.0 --port 3001 --disable-host-check"
```
