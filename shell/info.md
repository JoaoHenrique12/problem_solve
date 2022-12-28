# Shell

## Find file and remove it

Finding files starting witch first uppercase letter. 
```
find . -name '[A-Z]*' -type f -exec rm {} \;
```

- **find** : Find all files in the current directory.
- **name** '[A-Z]\*': Match files whose names start with an uppercase letter.
- **type**: Match only regular files (exclude directories, symbolic links, etc.).
- **exec rm {} \\;**: Execute the rm command on each matching file. 

The {} placeholder is replaced with the name of each matching file, and the \; tells the find command to terminate the -exec action.

## Find files containing word

```
grep -e "word" -rnw ./
```