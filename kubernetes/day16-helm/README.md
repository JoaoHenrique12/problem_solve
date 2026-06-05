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

## Explicacoes

### Hyphen

```yaml
ports:
  {{ range .Values.ports }}
  - containerPort: {{ . }}
  {{ end }}

# OUTPUT 
# ports:
#
#   - containerPort: 80
#
#   - containerPort: 443
```

```yaml
ports:
  {{- range .Values.ports }}
  - containerPort: {{ . }}
  {{- end }}
# OUTPUT
# ports:
#   - containerPort: 80
#   - containerPort: 443
```

### Separator

```yaml
# In Kubernetes, the triple dash --- is the official YAML stream separator. It tells the Kubernetes API (and Helm) that one
# resource definition has ended, and a brand new one is beginning within the exact same file.
{{- range $component, $config := .Values.services }}
  {{ range $port := $config.ports }}
apiVersion: v1
kind: Service
  # ...
  selector:
    app: {{ $config.labels.app }}
---
  {{ end }}
{{- end }}

```

Vamos resolver, mas antes, vamos mudar um pouco a organização em nosso
