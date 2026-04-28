# RBAC

## Criando usuario para acesso ao cluster

```bash
openssl ecparam -name prime256v1 -genkey -noout -out developer.key
openssl req -new -key developer.key -out developer.csr -subj "/CN=developer"
cat developer.csr | base64 | tr -d '\n'
# coloque o output em base64 no request de developer.yaml
k certificate approve developer
k get csr
k get csr developer -o jsonpath='{.status.certificate}' | base64 --decode > developer.crt
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
