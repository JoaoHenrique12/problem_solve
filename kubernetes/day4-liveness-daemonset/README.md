# ReplicaSet & DaemonSet

## ReplicaSet

é quem vai criar os Pods que estão dentro do Deployment;
É possível criar um ReplicaSet sem um Deployment, mas não é uma boa prática;

## DaemonSet

O DaemonSet é muito útil para executar Pods que precisam ser executados em todos
os nós do cluster, como por exemplo, um Pod que faz o monitoramento de logs, ou um
Pod que faz o monitoramento de métricas.

- Execução de agentes de monitoramento
- Execução de um proxy de rede em todos os nós do cluster



## Probes do kubernetes

### Liveness Probe

Verifica se o que está rodando dentro do Pod está saudável; se por acaso o teste falhar,
o Pod será reiniciado.

#### Using TCP PORT

```yaml
livenessProbe: # Aqui é onde vamos adicionar a nossa livenessProbe
  tcpSocket: # Aqui vamos utilizar o tcpSocket, onde vamos se conectar ao container através do protocolo TCP
    port: 80 # Qual porta TCP vamos utilizar para se conectar ao container
  initialDelaySeconds: 10 # Quantos segundos vamos esperar para executar a primeira verificação
  periodSeconds: 10 # A cada quantos segundos vamos executar a verificação
  timeoutSeconds: 5 # Quantos segundos vamos esperar para considerar que a verificação falhou
  failureThreshold: 3 # Quantos falhas consecutivas vamos aceitar antes de reiniciar o container
```

#### Using HTTP GET

```yaml
livenessProbe: # Aqui é onde vamos adicionar a nossa livenessProbe
  httpGet: # Aqui vamos utilizar o httpGet, onde vamos se conectar ao container através do protocolo HTTP
    path: / # Qual o endpoint que vamos utilizar para se conectar ao container
    port: 80 # Qual porta TCP vamos utilizar para se conectar ao container
  initialDelaySeconds: 10 # Quantos segundos vamos esperar para executar a primeira verificação
  periodSeconds: 10 # A cada quantos segundos vamos executar a verificação
  timeoutSeconds: 5 # Quantos segundos vamos esperar para considerar que a verificação falhou
  failureThreshold: 3 # Quantos falhas consecutivas vamos aceitar antes de reiniciar o container
```

### Readiness Probe

O container está pronto para receber tráfego, se ele está pronto para receber requisições vindas de fora.
Caso não esteja, ele não irá receber requisições, pois será removido do endpoint do serviço, fazendo com
que o tráfego não chegue até ele.

### Startup Probe

- "Na minha humilde opinião, é a menos utilizada" 
- Verificar se o container foi inicializado corretamente e está pronto para receber requisições;
- Parecido com a readinessProbe, mas a startupProbe é executada apenas uma vez no começo da vida do container


## Comandos

```bash
# scale pods
k scale deployment nginx-deployment --replicas=3
k describe replicaset nginx-replicaset

k delete replicaset nginx-replicaset


k describe daemonset node-exporter


# Criando daemonset na mao
k create daemonset node-exporter --image=prom/node-exporter:latest --port=9100 --host-port=9100
k create daemonset node-exporter --image=prom/node-exporter:latest --port=9100 --host-port=9100 -o yaml --dry-run=client > node-exporter-daemonset.yaml

k delete daemonset node-exporter

```
