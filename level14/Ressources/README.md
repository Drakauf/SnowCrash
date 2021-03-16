# Level14

Sur le home de l'utilisateur level14, nous trouvons les fichiers suivants : 
```
level14@SnowCrash:~$ ls -la
total 12
dr-x------ 1 level14 level14  100 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level14 level14  220 Apr  3  2012 .bash_logout
-r-x------ 1 level14 level14 3518 Aug 30  2015 .bashrc
-r-x------ 1 level14 level14  675 Apr  3  2012 .profile
```
Malheureusement, je n'ai pas trouvé quoi faire avec...
Nous allons donc nous pencher directement sur le bianire `/bin/getflag`.
Pour ce faire, à l'instar du level précédent nous allons utiliser gdb.
```
level14@SnowCrash:~$ gdb /bin/getflag
[...]
(gdb) disas main
Dump of assembler code for function main:
[...]
   0x08048989 <+67>:	call   0x8048540 <ptrace@plt>
   0x0804898e <+72>:	test   %eax,%eax              #breakpoint a cet endroit pour remplacer la sortie de ptrace
[...]
   0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
   0x08048b02 <+444>:	mov    %eax,0x18(%esp)        #breakpoint ici pour remplacer la valeur de 0x80484b0 par l'uid de flag14 (3014)
[...]
End of assembler dump.
(gdb) break *0x0804898e
Breakpoint 1 at 0x804898e
(gdb) break *0x08048b02
Breakpoint 2 at 0x8048b02
(gdb) r
Starting program: /bin/getflag

Breakpoint 1, 0x0804898e in main ()
(gdb) set $eax = 0
(gdb) s
Single stepping until exit from function main,
which has no line number information.

Breakpoint 2, 0x08048b02 in main ()
(gdb) set $eax = 0xbc6
(gdb) s
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```
