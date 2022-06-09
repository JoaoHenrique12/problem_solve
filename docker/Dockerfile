# Exec Dockerfile
  #portaMinha:portaImagem
docker run -d -p 8080:80 docker/getting-started
-d -> Deixa em back ground.
# Variavel de ambiente
-e MYSQL_ROOT=meuRoot -e

# ----- Docker container comands
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

# ------------ DOCKERFILE -----------------------

FROM node:12-alpine
# Adding build tools to make yarn install work on Apple silicon / arm64 machines
RUN apk add --no-cache python2 g++ make
WORKDIR /app
# Pasta atual para /app
COPY . .
RUN yarn install --production
CMD ["node", "src/index.js"]
EXPOSE 8080
# ----------- Volume && Network ------------------------------------
docker volume --help
docker volume prune // remove todos volumes nao usados, cuidado.

docker network

# ------------- docker-compose.yml ------------------------------
  # exec yml
docker compose up -d

# -------- Copiando arquivos entre o container e a maquina ------
docker cp id_container:/path ~/path_minha_maquina

# ------- Por que o container esta morrendo apos a execucao ?----
  # tem que adicionar um entry point.
https://devopscube.com/keep-docker-container-running/
