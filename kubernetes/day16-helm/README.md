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

### _helpers.tpl

Helpers no Helm são funções definidas em arquivos _helpers.tpl dentro do diretório templates de um gráfico Helm.
Eles permitem a reutilização de código e lógicas complexas em seus templates, promovendo práticas de codificação
DRY (Don't Repeat Yourself). 

#### Hello Helpers

```
# _helpers.tpl
{{/*
Define um helper para o nome do aplicativo.
*/}}
{{- define "meuapp.name" -}}
{{- default .Chart.Name .Values.appName | trunc 63 | trimSuffix "-" -}}
{{- end -}}
```

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: {{ include "meuapp.name" . }}
  labels:
    app: {{ include "meuapp.name" . }}
```

#### If else

```
{{/*
Gerar configuração específica do serviço.
*/}}
{{- define "meuapp.serviceConfig" -}}
{{- if eq .Values.serviceType "frontend" -}}
# Configuração específica do frontend
{{- else if eq .Values.serviceType "backend" -}}
# Configuração específica do backend
{{- end -}}
{{- end -}}
```

```
{{/*
Ajustar configurações com base no ambiente.
*/}}
{{- define "meuapp.envConfig" -}}
{{- if eq .Values.environment "prod" -}}
# Configurações de produção
{{- else -}}
# Configurações de desenvolvimento
{{- end -}}
{{- end -}}
```
