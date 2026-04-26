# Volumes

## Comandos

```bash
k get storageclass

# todos os Persistent Volume Claims que não tiverem um Storage Class definido, irão utilizar esse Storage Class como padrão.
k describe storageclass standard

# Lista todos os PV (Persistent Volumes)
k get pv -A
```

## Instrucoes

### Volumes são diretórios dentro de um pod.
- Ephemeral volumes (emptyDir)
- Persistent volumes

Uma StorageClass no Kubernetes é um objeto que descreve e define diferentes classes de armazenamento
disponíveis no cluster. 

Usado para gerenciar armazenamento entre discos rapidos e caros e lentos e baratos.

### PVC(Persistent Volume Claim)

O PVC é uma solicitação de armazenamento feita pelos usuários ou aplicativos no cluster Kubernetes.

O PVC age como uma "assinatura" que reivindica um PV para ser usado por um contêiner. 

Através do PVC, as pessoas podem abstrair os detalhes de cada tipo de armazenamento, permitindo maior flexibilidade e portabilidade entre diferentes ambientes e provedores de infraestrutura.

Todo PVC é associado a um Storage Class ou a um Persistent Volume. O Storage Class é um objeto que descreve e define diferentes classes de armazenamento disponíveis no cluster. Já o Persistent Volume é um recurso que representa um volume de armazenamento disponível para ser usado pelo cluster.
