# Cert-Manager

O Cert-Manager é um controlador do Kubernetes que automatiza a solicitação, emissão, renovação e rotação de certificados TLS de uma maneira fácil. 
Ele é capaz de gerenciar certificados de diferentes autoridades de certificação, como o Let's Encrypt, Venafi, Vault, entre outros. 

Cert-Manager:
- Issuers: emissão de certificados para um único namespace;
- ClusterIssuers: emissão de certificados para todos os namespaces do cluster.

Boa prática: utilizar um Issuer para o ambiente de desenvolvimento e um ClusterIssuer para o ambiente de produção.

O Let's Encrypt utiliza o protocolo ACME (Automatic Certificate Management Environment).
O ACME utiliza dois tipos de desafios para verificar a propriedade do domínio: HTTP-01 e DNS-01.

O desafio HTTP-01 é feito através da criação de um arquivo com um token específico no servidor web
que está respondendo pelas requisições do domínio. Já o desafio DNS-01 é feito através da criação de
um registro TXT no servidor de DNS do domínio.


Com o Cert-Manager configurado e o Ingress utilizando o ClusterIssuer para a emissão de certificados, a aplicação
já está disponível com o HTTPS. Podemos verificar o certificado acessando a aplicação pelo navegador e clicando
no cadeado ao lado do domínio.


## Instalando o Cert-Manager

Poderia usar um helm tambem.

```
kubectl apply -f https://github.com/cert-manager/cert-manager/releases/download/v1.14.1/cert-manager.yaml
```

## Comandos

```
# dada a instalacao do certmanager
k apply -f cluster-issuer.yaml
k apply -f issuer.yaml

# crie o ingress
k apply -f ingress-cluster-issuer.yaml

# validando se o certificado foi criado
k get certificates
k describe certificate giropops-containers-expert-tls

# olhando as orders
k get orders
k describe order giropops-containers-expert-tls
```

# Labels|Annotations

Annotations e labels são recursos do Kubernetes que permitem adicionar metadados aos recursos do cluster.
- Annotations: são pares chave-valor que podem ser utilizados para adicionar metadados adicionais aos recursos do cluster.
Como por exemplo, adicionar informações sobre a versão da aplicação, parâmetros de configuração, entre outros.
- Labels: também são pares chave-valor, mas são utilizadas para identificar e selecionar recursos do cluster.
Como por exemplo, adicionar uma label app: giropops para identificar todos os recursos relacionados a
aplicação giropops.

## Comandos

```
# use describe to see the labels along commands
# k describe pod/giropops-senhas-7fff8477bb-ggjtb
# k get pod giropops-senhas-6cf56b8c8-h2g9t -o jsonpath='{.metadata.labels}' | jq .


# list deploys
k apply -f labels-deploys/deployment.yaml
k get deploy --selector descomplicando=kubernetes

# list pods
k apply -f labels-deploys/deployment-2.yaml
k get pods --selector descomplicando=kubernetes

# list all
k get all --selector descomplicando=kubernetes

# adding label via comand line
k label|annotate pods --selector app=giropops complicando=terraform

# overwriting a label
k label|annotate pods --selector app=giropops complicando=cerraform --overwrite

# removing label
k label|annotate pods --selector app=giropops complicando-
```

# Ingress configs

```
k apply -f ingress/ingress-authenticate.yaml
```
