# Instalando Cluster Kubernetes

## Control Plane

- gerenciar namespaces, deployments, services, configmaps, secrets, etc.
- gerenciar workers do cluster
- gerenciar rede do cluster
- etcd armazena as informações de configuração de todos os componentes do control plane
  - Design distribuido
  - tolerar falhas
  - comunicação segura entre os componentes do cluster usando TLS
- scheduler é o componente responsável por decidir em qual nó os pods serão executados,
se necessário, ajusta a distribuição dos pods para garantir a melhor utilização dos recursos
e manter a harmonia entre os componentes.
- controller manager gerenciar os diferentes controladores que regulam o estado do cluster e 
mantêm tudo funcionando
- api-server componente central que expõe a API do Kubernetes, permitindo que outros componentes
do control plane, como o controller-manager e o scheduler, bem como ferramentas externas, se
comuniquem e interajam com o cluster.

## Worker

- kubelet é o agente que funciona em cada nó do cluster, garantindo que os containers estejam funcionando
conforme o esperado dentro dos pods.
- kube-proxy, que é o componente responsável fazer ser possível que os pods e os services se comuniquem 
entre si e com o mundo externo.
