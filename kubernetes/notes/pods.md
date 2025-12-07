# Pods

[day2](../day2/README.md)

## extact info

```bash
kubectl get pod <pod-name> --namespace <namespace> -o yaml
```

## Create/Delete

### Via command line
```bash
k run nginx --image nginx
k delete pod nginx
```

### Via arquivo de manifesto

```bash
# Criando
k run meu-nginx --image nginx --port=80 --dry-run=client -o yaml > pod-template.yaml

# Aplicando
k apply -f pod-template.yaml

# Deletando
k delete -f pod-template.yaml
```

## List

```bash
k get pod -n namespace
k get pods -A -o wide
```


## Attach/Exec

### Attach

```bash
# conectar a um container que está rodando dentro de um Pod,
# e não para executar comandos dentro do container.
k attach giropops -c strigus
```

### Exec

```bash
k exec giropops -c strigus -- ls

k exec giropops -c strigus -it -- sh
```
