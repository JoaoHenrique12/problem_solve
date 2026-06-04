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

## Exemplo didatico sobre range, fazendo o deploy do redis + app ao mesmo tempo

```yaml
{{- range $component, $config := .Values.deployments }}
apiVersion: apps/v1
kind: Deployment
metadata:
  name: {{ $component }}
  labels:
    app: {{ $config.labels.app }}
spec:
  replicas: {{ $config.replicas }}
  selector:
    matchLabels:
      app: {{ $config.labels.app }}
  template:
    metadata:
      labels:
        app: {{ $config.labels.app }}
    spec:
      containers:
      - name: {{ $component }}
        image: {{ $config.image }}
        ports:
        {{- range $config.ports }}
        - containerPort: {{ .port }}
        {{- end }}
        resources:
          requests:
            memory: {{ $config.resources.requests.memory }}
            cpu: {{ $config.resources.requests.cpu }}
          limits:
            memory: {{ $config.resources.limits.memory }}
            cpu: {{ $config.resources.limits.cpu }}
{{- if $config.env }}
        env:
        {{- range $config.env }}
        - name: {{ .name }}
          value: {{ .value }}
        {{- end }}
{{- end }}
---
{{- end }}
```
