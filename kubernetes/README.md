# Notas sobre o Descomplicando Kubernetes

[fork](https://github.com/JoaoHenrique12/DescomplicandoKubernetes)

## Kubectl

```bash
k get nodes
k get pods
k get namespaces
k get services

k get pod -n namespace

k get pods -A -o wide
```

### Criando e deletando pods

```bash
k run nginx --image nginx
k delete pod nginx
```

Arquivo de manifesto

```bash
# Criando
k run meu-nginx --image nginx --port=80 --dry-run=client -o yaml > pod-template.yaml

# Aplicando
k apply -f pod-template.yaml

# Deletando
k delete -f pod-template.yaml
```

### Expondo o pod

```bash
k expose pod meu-nginx
k get services
```
