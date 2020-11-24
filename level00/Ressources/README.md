# Level00

Une fois connecté avec le username:motdepasse level00:level00, nous arrivons sur le home de l'utilisateur level00.  
Il est vide et ne contient aucun fichier sortant de l'ordinaire. On se dirige donc sur la racine.  
On peut apercevoir que nous n'avons pas beaucoup de droits en tant qu'utilisateur level00 sur la racine.  
Nous allons donc chercher un ou des fichier(s) sur le(s) quel(s) l'utilisateur level00 ou flag00 à les droits. 
  
La commande `find -group flag00  2> /tmp/test` nous donne le résultat suivant :  
```
level00@SnowCrash:/$ find -group flag00  2> /tmp/test
./usr/sbin/john
./rofs/usr/sbin/john
```
Un `cat` de l'un des deux fichiers donne le résultat suivant : 
```
level00@SnowCrash:/$ cat /usr/sbin/john
cdiiddwpgswtgt
```
rofs étant une copie de l'iso en readonly, il y a exectement la même chose dans l'autre fichier.  
En faisant un ROT 11 de la chaine de caractère, on trouve `nottoohardhere`.  
Il nous reste donc plus qu'à aller chercher le flag en nous connectant sur le compte flag00.  
```
level00@SnowCrash:/$ su flag00
Password:nottoohardhere
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```

Pour passer au level01, il nous suffit de changer d'utilisateur :
```
flag00@SnowCrash:~$ su level01
Password:x24ti5gi3x0ol2eh4esiuxias
```


||<h3 align="center"> Documentation </h3>|
|:--------:|:---------:|
|ROT|https://www.apprendre-en-ligne.net/crypto/cesar/index.html|
