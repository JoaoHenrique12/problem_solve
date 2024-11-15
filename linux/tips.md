# Linux commands

## Convert to gif

```
ffmpeg -i presentation.mkv -vf "fps=15,scale=854:-1:flags=lanczos" -c:v gif -r 15 -speed 1.7 presentation.gif
```
