//portaMinha:portaImagem
docker run -d -p 8080:80 docker/getting-started

-d -> Deixa em back ground.

docker container help

docker stop 5bb95ca56732
docker start 5bb95ca56732
docker restart 5bb95ca56732
docker rm 5bb95ca56732

docker rm --force 5bb95ca56732

docker container ls -a
docker container logs -f 5bb95ca56732

docker container exec help

docker container exec -it 5bb95ca56732 bash

# Build de meu Dockerfile
docker build -t nome-tag ./folder_dockerfile

docker images
docker image inspect getting-started:latest
docker image tag nomeantigo:2.0 nomenovo:latest

// ------------ DOCKERFILE -----------------------

FROM node:12-alpine
# Adding build tools to make yarn install work on Apple silicon / arm64 machines
RUN apk add --no-cache python2 g++ make
WORKDIR /app
# Pasta atual para /app
COPY . .
RUN yarn install --production
CMD ["node", "src/index.js"]
EXPOSE 8080
// --------
docker volume
docker network
