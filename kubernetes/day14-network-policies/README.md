# Network Policies

- Por padrão, os Pods em um cluster Kubernetes podem se comunicar livremente entre si;
- Network Policies
  - Isolar Pods de tráfego não autorizado.
  - Controlar o acesso à serviços específicos.
  - Implementar padrões de segurança e conformidade.
- Utilizam SELECTORS para identificar grupos de Pods e definir regras de tráfego para eles. A política pode especificar:
  - Ingress: quais Pods ou endereços IP podem se conectar a Pods selecionados.
  - Egress: para quais Pods ou endereços IP os Pods selecionados podem se conectar.
```bash
# validando se o cluster k8s suporta network policies
k api-versions | grep networking
k get pods -n kube-system -l k8s-app=calico-node
# if there i no pods running, delete the cluster and restart with a new one.
# minikube delete
minikube start --cni=calico
```

## Exemplo

### cluster

```bash
k create ns giropops
k apply -f cluster/giropops-deployment.yaml -n giropops
k apply -f cluster/giropops-service.yaml -n giropops
k apply -f cluster/redis-deployment.yaml -n giropops
k apply -f cluster/redis-service.yaml -n giropops 
k apply -f cluster/giropops-ingress.yaml -n giropops
# minikube tunnel, ajuste no dns, revisitar day09
# vi /etc/hosts
```

### policies

#### Acesso ao redis somente internamente

```bash
k apply -f policies/allow-redis-ns.yaml

# testando acesso ao redis de fora do namespace giropops
k run -it --rm --image redis redis-client -- sh

# testando acesso ao redis de dentro do namespace giropops
k run -it --rm -n giropops --image redis redis-client -- sh

# inside container use:
# redis-cli -h redis-service.giropops.svc.cluster.local ping
```

#### Pods de giropops so recebem chamadas de pods giropops

```bash
k apply -f policies/disallow-all-out-giropops.yaml

# testando acesso de fora do cluster
k run -it --rm --image curlimages/curl curl-client -- sh

# testando acesso de dentro do cluster
k run -it -n giropops --rm --image curlimages/curl curl-client -- sh

# inside container use:
# curl giropops-senhas.giropops.svc
```
