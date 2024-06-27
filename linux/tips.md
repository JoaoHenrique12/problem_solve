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

### Find and replace

```bash
grep -rlw pattern | xargs sed -i 's/pattern/new_pattern/g'
```

## [Tmux](https://hamvocke.com/blog/a-quick-and-easy-guide-to-tmux/)

[Cheat sheet](https://tmuxcheatsheet.com/)

```bash
tmux

# Open in vsplit
# <c-b> +  %

# Open in split
# <c-b> +  "

# Change window
# <c-b> +  arrow_key

# Create a new window
# <c-b> + c
# <c-b> + p/n -> previous and next
# <c-b> + w -> show windows
# <c-b> + , -> rename window
# <c-b> + & -> kill window

# Deataching
# <c-b> + d

# Attaching
# tmux ls
# tmux attach -t 0

# Giving names to sessions
# tmux new -s database

# Renaming sessions
# tmux rename-session -t 0 database

# <c-b> + z -> Go full scree
# <c-b> + arrow_key hold -> resize window.

```

