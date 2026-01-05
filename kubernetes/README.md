# Notas sobre o Descomplicando Kubernetes

[fork](https://github.com/JoaoHenrique12/DescomplicandoKubernetes)

[k9](https://github.com/derailed/k9s)

## Kubectl

```bash
k get nodes
k get pods
k get namespaces
k get services
```

### Expondo o pod

```bash
k expose pod meu-nginx
k get services
```

### Port-forward

```bash
k port-forward service/giropops-senhas 5000:5000
k port-forward deployment/giropops-senhas 5000:5000
k port-forward pod/giropops-senhas 5000:5000
```
