# Taints, Tolerations, Affinity

Isolar workloads, garantir que Pods sejam agendados em Nodes específicos e até mesmo evitar que pods sejam
agendados em determinados Nodes do cluster.

Exemplo:
- Cluster de produção com 8 nodes (4 control planes + 4 workers)
  - strigus-br-sp
    - strigus-br-sp-1
      - strigus-control-plane1
      - strigus-worker3
    - strigus-br-sp-2
      - strigus-control-plane4
      - strigus-worker1
  - strigus-br-ssa
    - strigus-br-ssa-1
      - strigus-control-plane2
      - strigus-worker2
    - strigus-br-ssa-2
      - strigus-control-plane3
      - strigus-worker4
```bash
# criando labels (region, datacenter) para cada node
k label nodes strigus-control-plane1 region=strigus-br-sp datacenter=strigus-br-sp-1
k label nodes strigus-control-plane2 region=strigus-br-ssa datacenter=strigus-br-ssa-1
k label nodes strigus-control-plane3 region=strigus-br-ssa datacenter=strigus-br-ssa-2
k label nodes strigus-control-plane4 region=strigus-br-sp datacenter=strigus-br-sp-2
k label nodes strigus-worker1 region=strigus-br-sp datacenter=strigus-br-sp-2
k label nodes strigus-worker2 region=strigus-br-ssa datacenter=strigus-br-ssa-1
k label nodes strigus-worker3 region=strigus-br-sp datacenter=strigus-br-sp-1
k label nodes strigus-worker4 region=strigus-br-ssa datacenter=strigus-br-ssa-2
```

```bash
# adicionando label de gpu nos workers
k label nodes strigus-worker1 gpu=true
k label nodes strigus-worker4 gpu=true
```

## Taints

- **NoSchedule**: faz com que o Kubernetes não agende Pods nesse Node a menos que eles tenham uma Toleration correspondente.
- **PreferNoSchedule**: faz com que o Kubernetes tente não agendar, mas não é uma garantia.
- **NoExecute** faz com que os Pods existentes sejam removidos se não tiverem uma Toleration correspondente.

```bash
# key, value são valores arbitrários

# adiciona taint
k taint nodes strigus-worker1 key=value:NoSchedule

# visualisa taint
k describe node strigus-worker1

# remove taint
k taint nodes strigus-worker1 key=value:NoSchedule-

# adiciona taint no-execute
# -------------------------
# os pods que estavam sendo executados no node strigus-worker1 foram removidos e
# agendados em outros nodes.
k taint nodes strigus-worker1 key=value:NoExecute

# adiciona taint PreferNoSchedule
k taint nodes strigus-worker1 key=value:PreferNoSchedule
```

## Tolerations

- tolerations não fazem com que o pod seja agendado nesses nodes, mas permite que ele seja agendado nesses nodes.
```bash
k taint nodes strigus-worker1 gpu=true:NoSchedule
k apply -f gpu-deployment.yaml
```

## Affinity, Antiaffinity
