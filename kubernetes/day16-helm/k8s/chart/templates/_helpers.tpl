{{/*
Generate application labels
*/}}
{{- define "app.labels" -}}
app: {{ .labels.app }}
env: {{ .labels.env }}
live: {{ .labels.live | quote }}
{{- end }}

{{/*
Generate container resources
*/}}
{{- define "app.resources" -}}
requests:
  memory: {{ .resources.requests.memory }}
  cpu: {{ .resources.requests.cpu }}
limits:
  memory: {{ .resources.limits.memory }}
  cpu: {{ .resources.limits.cpu }}
{{- end }}

{{/*
Generate container ports
*/}}
{{- define "app.ports" -}}
{{- range .ports }}
- containerPort: {{ .port }}
{{- end }}
{{- end }}
