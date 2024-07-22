# Docker tips

## Execute a image with you command is

```bash
docker run -it <image_name> /bin/bash

docker-compose run -it <image_name> /bin/bash # With it your volumes will be keeped.
```

## Force rebuild image

- --no-deps: unconsider dependencies
- -d: daemon

```bash
docker-compose up -d --no-deps --build <service_name>
```
