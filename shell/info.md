# Shell

## Find

### Find file and remove it

Finding files starting witch first uppercase letter. 
```
$ find . -name '[A-Z]*' -type f -exec rm {} \;
```

- **find** : Find all files in the current directory.
- **name** '[A-Z]\*': Match files whose names start with an uppercase letter.
- **type**: Match only regular files (exclude directories, symbolic links, etc.).
- **exec rm {} \\;**: Execute the rm command on each matching file. 

The {} placeholder is replaced with the name of each matching file, and the \; tells the find command to terminate the -exec action.

### Find files containing word

```
$ grep -e "word" -rnw ./
```

## Permissions

#### Tipos de permisões

- 4 read
- 2 write
- 1 execute

#### Grupos de permisões

1. Seu usuário
1. Seu grupo
1. Todos os outros usuários

```
$ chmod 722 -R src/
$ # Agora passe estas permissões para o usuário www-data
$ chown -R www-data:www-data src/
```

## Configurando ssh

- /etc/ssh/sshd\_config

## Show wifi

nmcli dev wifi show-password
