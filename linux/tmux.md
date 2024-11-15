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

```bash
# Plugins:
# tmux ressurect
# Save session:<c-b> + <c-s>
# Restore session:<c-b> + <c-r>
```
