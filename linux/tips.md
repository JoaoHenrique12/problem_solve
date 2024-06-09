# Linux commands

## Convert to gif

```
ffmpeg -i presentation.mkv -vf "fps=15,scale=854:-1:flags=lanczos" -c:v gif -r 15 -speed 1.7 presentation.gif
```

## Find words in files

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
