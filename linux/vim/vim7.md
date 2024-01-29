# [tutorial_vim](https://learnvim.irian.to)

## External Commands

!
- Read the STDOUT of an external command into the current buffer. (:r !ls)
- Write the content of your buffer as the STDIN to an external command.(:w !node)
- Execute an external command from inside Vim. (:!ls)

```
hello vim
hello vim

:.!tr '[:lower:]' '[:upper:]'
```
