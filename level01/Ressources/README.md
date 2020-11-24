# Level01

Une fois connecté avec le username:motdepasse level01:x24ti5gi3x0ol2eh4esiuxias (obtenu dans le flag précédent), nous arrivons sur le home de l'utilisateur level01.  
Il est vide et ne contient aucun fichier sortant de l'ordinaire. On se dirige donc sur la racine.
On remarque facilement dans le fichier `etc/passwd` une chaîne de caractère en tant que mot de passe pour le flag01 :  
`flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`. 

Après une petite recherche des différents moyen de casser un mot de passe nous tombons sur `John The Ripper (JTR pour les intimes)`  
`john` étant aussi le nom du fichier dans lequel nous avons eu un indice dans le level00.


||<h3 align="center"> Documentation </h3>|
|:--------:|:---------:|
|Moyen de cassage de mot de passe |https://www.presse-citron.net/10-outils-utilises-par-les-hackers-pour-cracker-les-mot-de-passe-ou-comment-mieux-securiser-les-votres/|
