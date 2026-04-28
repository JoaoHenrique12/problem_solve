# Notas sobre o Descomplicando Kubernetes

[fork](https://github.com/JoaoHenrique12/DescomplicandoKubernetes)

[k9](https://github.com/derailed/k9s)

## Kubectl

```bash
k api-resources
k get nodes
k get pods
k get namespaces
k get services
k get netpol
k logs -f --tail=20 --prefix <pod-name>
k logs -f deployment/<deployment-name> --all-pods=true

# certificate sign request
kubectl get csr

# contexts, multiple clusters kubernetes
k config get-contexts
k config current-context
```

```bash
# create a pod for test and delete it after execution
k run -it --rm --image curlimages/curl curl-client -- sh
```

### Expondo o pod (service)

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
