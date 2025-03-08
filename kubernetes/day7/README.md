# StatefulSet & Service

## Commands

```bash
# Comando para criar e executar um pod de debug
k run -it --rm debug --image=busybox --restart=Never -- sh
```

```bash
k get endpoints meu-service
```

```bash
# Criando um service (NodePort) via linha de comando
k expose deployment MEU_DEPLOYMENT --port=80 --type=NodePort

# Criando um ClusterIP
#                                  porta de saida porta dos pods
k expose deployment meu-deployment --port=80 --target-port=8080

# Criando um NodePort
k expose deployment meu-deployment --type=NodePort --port=80 --target-port=8080

# Criando um LoadBalancer
k expose deployment meu-deployment --type=LoadBalancer --port=80 --target-port=8080

# Criando um external name
k create service externalname meu-service --external-name meu-db.giropops.com.br
```

## StatefulSets

- Não é possível criar um StatefulSet sem um manifesto yaml, diferente do que acontece com o Pod e o Deployment.
- StatefulSets: criar aplicações que precisam manter a identidade do Pod.
- Caos comuns são bancos de dados, sistemas de mensageria e sistemas de arquivos distribuídos.
- Garantem que nomes e endereços dos Pods sejam consistentes e estáveis ao longo do tempo.

-----
- Identidade de rede estável e única.
- Armazenamento persistente estável.
- Ordem de deployment e scaling garantida.
- Ordem de rolling updates e rollbacks garantida.
- Algumas aplicações que se encaixam nesses requisitos são bancos de dados, sistemas de filas e quaisquer aplicativos que necessitam de persistência de dados ou identidade de rede estável.

----
Os pods criados podem ser diferenciados pelo seu indice e hostname.

StatefulSet com nome giropops com 3 replicas, nomes:
- giropops-0
- giropops-1 (só está disponível quando 0 fica pronto)
- giropops-2

- Por padrão, o Kubernetes cria um PersistentVolume para cada Pod em um StatefulSet.
- O StatefulSet e volumes persistentes: Quando um Pod é recriado, ele se reconecta ao mesmo Volume Persistente, garantindo a persistência dos dados entre as recriações dos Pods.

## Service

- O Service é um objeto que permite que você expor uma aplicação para o mundo externo. Ele é responsável por fazer o balanceamento
de carga entre os Pods que estão sendo expostos e também por fazer a resolução de nomes DNS para os Pods que estão sendo expostos.

- Resolução DNS: <pod-name>.<service-name>.<namespace>.svc.cluster.local
- Um serviço é uma abstração que define um conjunto lógico de Pods e uma maneira de acessá-los. Normalmente, um serviço tem um IP e encaminha o tráfego para os Pods.
- No entanto, um Headless Service é um tipo especial de serviço que não tem um IP próprio. Em vez disso, ele retorna diretamente os IPs dos Pods que estão associados a ele.
-----

Tipos de services:

- ClusterIP (padrão): Expõe o Service em um IP interno no cluster. Este tipo torna o Service acessível apenas dentro do cluster.
- NodePort: Expõe o Service na mesma porta de cada Node selecionado no cluster usando NAT. Torna o Service acessível de fora do cluster usando :.
- LoadBalancer: Cria um balanceador de carga externo no ambiente de nuvem atual (se suportado) e atribui um IP fixo, externo ao cluster, ao Service.
- ExternalName: Mapeia o Service para o conteúdo do campo externalName (por exemplo, foo.bar.example.com), retornando um registro CNAME com seu valor.
-----

- Embora cada Pod tenha um endereço IP único, esses IPs não são expostos fora do cluster sem um serviço.
- Sempre é bom reforçar a importância dos Labels no Kubernetes, pois eles são a base para a maioria das operações no Kubernetes, então cuide com carinho dos seus Labels.
- podemos criar um Service para um Pod, um ReplicaSet, um ReplicationController ou até mesmo para outro Service.

- External name não expõe um conjunto de Pods, mas sim um nome de host externo. 
- O service ExternalName é útil quando você quer
  - Criar um alias para um serviço externo
  - Abstrair serviços dependentes do ambiente:  Outro uso comum para ExternalName é quando você tem ambientes diferentes, como produção e desenvolvimento, que possuem serviços externos diferentes. Você pode usar o mesmo nome de serviço em todos os ambientes, mas apontar para diferentes endereços externos.

- Os Endpoints são uma parte importante dos Services, pois eles são responsáveis por manter o mapeamento entre o Service e os Pods que ele está expondo.
