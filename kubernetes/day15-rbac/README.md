# RBAC

## Criando usuario para acesso ao cluster

```bash
openssl ecparam -name prime256v1 -genkey -noout -out developer/developer.key
openssl req -new -key developer/developer.key -out developer/developer.csr -subj "/CN=developer"
cat developer/developer.csr | base64 | tr -d '\n'
# coloque o output em base64 no request de developer.yaml
k apply -f developer/developer.yaml
k certificate approve developer
k get csr
k get csr developer -o jsonpath='{.status.certificate}' | base64 --decode > developer/developer.crt
```

Dentro da Role é onde definimos:

- qual é o namespace que o usuário terá acesso.
- quais apiGroups o usuário terá acesso.
  - k api-resources --namespaced=false
  - grupos de recursos do Kubernetes, que são divididos em core e named, você pode consultar todos os grupos de recursos
  do Kubernetes através do comando kubectl api-resources
- quais recursos o usuário terá acesso.
- quais verbos o usuário terá acesso.
  - k api-resources -o wide
```bash
k create ns dev
k apply -f developer/developer-role.yaml
k get roles -n dev
k describe role developer -n dev
```

Criando um RoleBinding
- uma rolebinding faz o attach de um user a uma role
```bash
k apply -f developer/developer-rolebinding.yaml
k get rolebindings -n dev
```

Adicionando o certificado do usuario no kubeconfig
```bash
k config set-credentials developer --client-certificate=developer/developer.crt --client-key=developer/developer.key --embed-certs=true

# pegar o nome do cluster
# k config get-clusters
k config set-context developer --cluster=minikube --namespace=dev --user=developer
# k config get-contexts
# trocando de contextos
k config use-context developer
```

## ClusterRole, ClusterROleBinding

```bash
k config use-context minikube
openssl ecparam -name prime256v1 -genkey -noout -out platform/platform.key
openssl req -new -key platform/platform.key -out platform/platform.csr -subj "/CN=platform/O=platform"
cat platform/platform.csr | base64 | tr -d '\n'
# coloque o output em base64 no request de platform.yaml
k apply -f platform/platform.yaml
k certificate approve platform
k get csr
k get csr platform -o jsonpath='{.status.certificate}' | base64 --decode > platform/platform.crt
k apply -f platform/platform-role.yaml
k apply -f platform/platform-rolebinding.yaml
k get clusterroles
k get clusterrolebindings

# adicionar certificados no cluster
k config set-credentials platform --client-certificate=platform/platform.crt --client-key=platform/platform.key --embed-certs=true
k config set-context platform --cluster=minikube --user=platform
k config use-context platform
k get pods -A
```

```bash
# admin account
openssl ecparam -name prime256v1 -genkey -noout -out admin/admin.key
openssl req -new -key admin/admin.key -out admin/admin.csr -subj "/CN=admin/O=admin"
cat admin/admin.csr | base64 | tr -d '\n'
# coloque o output em base64 no request de admin.yaml
k apply -f admin/admin.yaml
k certificate approve admin
k get csr
k get csr admin -o jsonpath='{.status.certificate}' | base64 --decode > admin/admin.crt
k apply -f admin/admin-role.yaml
k apply -f admin/admin-rolebinding.yaml
k get clusterroles
k get clusterrolebindings

# adicionar certificados no cluster
k config set-credentials admin --client-certificate=admin/admin.crt --client-key=admin/admin.key --embed-certs=true
k config set-context admin --cluster=minikube --user=admin
k config use-context admin
k get pods -A

# comando para saber de tudo o que um usuario pode fazer no cluster.
k auth can-i --list
```
