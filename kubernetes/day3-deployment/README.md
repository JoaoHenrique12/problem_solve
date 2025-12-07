# Deployment

Deployment é um objeto que representa uma aplicação.
  - Gerencia/Atualiza pods
  - Faz rollback
  - Ao criar um Deployment um ReplicaSet é criado também.

Você não pode criar um único Deployment que gerencie dois tipos diferentes de Pods. Um Deployment é projetado para gerenciar um conjunto
de réplicas idênticas de um único modelo de Pod, definido na seção template. Se você precisar de dois tipos diferentes de Pods, a maneira
correta no Kubernetes é criar dois Deployments separados

## Update Deployments

### RollingUpdate

- estratégia padrão de atualização do kubernetes
- atualiza os pods de forma gradual, atualiza um pod ou grupo de pods por vez

```yaml
strategy:
  type: RollingUpdate
  rollingUpdate:
    maxSurge: 1
    maxUnavailable: 2
```

maxSurge -> Quantidade máxima de pods que podem ser criados
maxUnavailable -> Quantidade máxima de pods que podem ficar indisponíveis

### Recreate

- irá remover todos os Pods do Deployment e criar novos Pods com a nova versão da imagem. 
- acontecerá rapidamente
- ficará indisponível durante a atualização

```yaml
  strategy:
    type: Recreate
```

## Comandos

```bash
k get deployments -l app=nginx-deployment
k get pods -l app=nginx
k get replicasets -l app=nginx-deployment

k describe deployment nginx-deployment

# Acompanhar o processo de atualização dos pods
k rollout status deployment nginx-deployment

# Rollback command
k rollout undo deployment nginx-deployment
k rollout undo deployment nginx-deployment --to-revision=1

# Rollback history
k rollout history deployment nginx-deployment
k rollout history deployment nginx-deployment --revision=1

# pausar um deployment
k rollout pause deployment nginx-deployment
k rollout resume deployment nginx-deployment

# reiniciar o Deployment, ou seja, ele vai reiniciar o Deployment recriando os Pods.
k rollout restart deployment nginx-deployment

# Criando e deletando deployment
k apply -f deployment.yaml 
k delete -f deployment.yaml

# Deletando sem o manifesto
k delete deployment nginx-deployment
```
