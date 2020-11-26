# Level03

Une fois connecté avec le username:motdepasse level03:kooda2puivaav1idi4f57q8iq (obtenu dans le flag précédent), nous arrivons sur le home de l'utilisateur level03.  
Nous pouvons y trouver un exécutable nommé `level03`.  
En l'exécutant on obtient : 
```
level03@SnowCrash:~$ ./level03
Exploit me
```

Nous allons essayer de décortiquer l'exécutable afin de pouvoir l'exploiter.  
En utilisant `strings level03`, nous pouvons trouver la ligne suivante : `/usr/bin/env echo Exploit me`. 
Le programme utilise le binaire `echo` via `/usr/bin/env`  
Nous allons utiliser le fait que cet executable appelle `echo`. Nous voulons appeler la commande getflag.  

Pour ce faire nous allons faire en sorte que le binaire de echo soit substitué par celui de getflag lors de son appel par l'exécutable.  
Nous allons créer un lien symbolique d'echo vers getflag :  
`ln -s /bin/getflag /tmp/echo`  

Nous allons ensuite ajouter le tmp dans la variable d'environement PATH afin que le lien soit appelé, en faisant bien attention a rajouter `/tmp` au debut de PATH.  
`export PATH=/tmp:$PATH`

Ensuite nous lançons l'executable:  
```
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```
