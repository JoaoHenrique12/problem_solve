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

Readiness Probe; Liveness Probe; Startup Probe;


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
