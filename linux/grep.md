# Find words in files

```bash
grep -rnw word

# -l to show file name
```

```bash
grep -rnw /path/to/folder -e word
```

```bash
grep --include=\*.{c,h} -rnw '/path/to/somewhere/' -e "pattern"
```

### Find and replace

```bash
grep -rlw pattern | xargs sed -i 's/pattern/new_pattern/g'
```
