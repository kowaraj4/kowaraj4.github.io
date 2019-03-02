# shapkee

##  Run

### 1. Start the Backend to serve static files from ./public
```
[root@d777a1dfc437 build]# pwd
/src/shapkee/build
[root@d777a1dfc437 build]# ../node_modules/.bin/http-server .
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
