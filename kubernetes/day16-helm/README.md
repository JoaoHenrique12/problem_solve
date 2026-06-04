# Helm

Um Chart é um pacote que contém informações necessárias para criar instâncias de aplicações Kubernetes.
É com ele que iremos definir como a nossa aplicação será instalada, quais configurações serão utilizadas
e como será feita a atualização da aplicação. Um Chart normalmente é composto por um conjunto de arquivos
que definem a aplicação e um conjunto de templates que definem como a aplicação será instalada no Kubernetes.

```bash
git clone git@github.com:badtuxx/giropops-senhas.git

# Once with chart ready use
# cd chart/
helm template --debug --show-only templates/senhas-service.yaml k8s/chart/
helm install giropops-senhas k8s/chart/
helm list -n default # --all-namespaces
helm get all giropops-senhas
helm upgrade giropops-senhas k8s/chart/
helm uninstall giropops-senhas
# helm create app-name generates a boilerplate for new helms
```
