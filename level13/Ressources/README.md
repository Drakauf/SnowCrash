# Level13
Nous arrivons sur le home de l'utilisateur et nous y trouvons un executable.
En le lançant nous obtenons ceci :
```
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
```

Avec gdb level13: 

```
disas main        -> desassembler le main
                  -> on recupere l'addresse ou a lieu la comparaison des UID -> 0x0804859a
b *0x0804859a     -> on met un breakpoint a cette adresse la
run               -> on lance l'executable qui s'arrete au breakpoint
set $eax = 0x1092 -> on remplace la valeur de base du UID par 0x1092 (4242 en exa)
continue          -> poursuivre l'execution
```
Nous obtenons : `your token is 2A31L79asukciNyi8uppkEuSx`
