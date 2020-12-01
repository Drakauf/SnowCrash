# Level09

Sur le home de l'utilisateur level09, à l'instar du level08 nous y trouvons un fichier token et un exécutable portant le nom de l'utilisateur.  
Effectuons des tests :  

```sh
level09@SnowCrash:~$ ./level09 token
tpmhr
level09@SnowCrash:~$ cat token
f4kmm6p|=�p�n��DB�Du{��
level09@SnowCrash:~$ touch /tmp/test
level09@SnowCrash:~$ ./level09 /tmp/test
/uos3ykz|
level09@SnowCrash:~$ echo "hello" > /tmp/test
level09@SnowCrash:~$ ./level09 /tmp/test
/uos3ykz|
level09@SnowCrash:~$ ./level09 /tmp/test
/uos3ykz|
level09@SnowCrash:~$ ./level09 /tmp
/uos
```
Nous pouvons nous apperçevoir que l'exécutable ne prend pas un fichier en paramétre mais plutot une chaine de caractére, nous effectuons d'autres tests :  
```
level09@SnowCrash:~$ ./level09 /test
/ugvx
level09@SnowCrash:~$ ./level09 test
tfuw
level09@SnowCrash:~$ ./level09 abc
ace
level09@SnowCrash:~$ ./level09 a
a
level09@SnowCrash:~$ ./level09 aaaaa
abcde
level09@SnowCrash:~$ ./level09 12345
13579
```
Nous nous en rendant compte que l'excutable prend chaque caractére de la chaine et lui ajoute son index : 
"a" = a -> a + 0
"aaaaa" = a + 0; a + 1 (b); a + 2 (c) ; a + 3 (d) ; a + 5 (e)
"12345" = 1 + 0; 2 + 1 (3); 3 + 2 (5); 4 + 3 (7); 5 + 4 (9)

Nous allons donc faire un programme pour decoder le fichier 'token', qui content 26bytes :   
```sh
42Cursus scp -P 4242 level09@localhost:~/token .
	   _____                      _____               _
	  / ____|                    / ____|             | |
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          10.0.2.15
level09@localhost's password:25749xKZ8L7DkSCwJkT9dyv6f
token                           100%   26    25.3KB/s   00:00
➜  42Cursus ./a.out token
f3iji1ju5yuevaus41q1afiuq
```
Il ne nous reste plus qu'à aller récupérer le flag : 
```sh
level09@SnowCrash:~$ su flag09
Password:f3iji1ju5yuevaus41q1afiuq
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```
