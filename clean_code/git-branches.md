delete branches:

- git fetch --prune origin
- git branch | grep -v "main" | xargs git branch -D
