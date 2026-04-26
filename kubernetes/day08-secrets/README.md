# Secrets & ConfigMaps

## Códigos

```bash
# O -n faz a não adição de uma quebra de linha no final do texto.
echo -n 'giropops' | base64
echo -n 'Z2lyb3BvcHM=' | base64 -d

# Recuperando as secrets
k get secret giropops-secret -o yaml

# --from-file; --from-env-file
k create secret generic giropops-secret --from-literal=username=segredo --from-literal=password=giropops

# Gerando chave certificado TLS auto assinado
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout chave-privada.key -out certificado.crt

# Criando secret para certificado TLS
k create secret tls meu-servico-web-tls-secret --cert=certificado.crt --key=chave-privada.key

# Dockerhub credentials
base64 ~/.docker/config.json

# Configmap usando cmd

k create configmap nginx-config --from-file=nginx.conf

# Service Default

k expose pod nginx
k port-forward service/nginx 4443:443
```

## Secrets

- São armazenadas no ETCD, por padrão não são criptografadas. O acesso é feito por meio de RBAC.
- Os Secrets podem ser montados em Pods como arquivos em volumes ou podem ser usados para preencher variáveis de ambiente para um container dentro de um Pod.
- Quando um Secret é atualizado, o Kubernetes não atualiza automaticamente os volumes montados ou as variáveis de ambiente que se referem a ele.

----

### Tipos de Secrets

- Opaque Secrets: mais comuns, são codificados em base64, podem ser usados para armazenar dados confidenciais, mas não são seguros o suficiente para armazenar informações altamente sensíveis, como senhas de banco de dados.
- kubernetes.io/service-account-token - são usados para armazenar tokens de acesso de conta de serviço. Esses tokens são usados para autenticar Pods com o Kubernetes API. Eles são montados automaticamente em Pods que usam contas de serviço.
- kubernetes.io/dockercfg e kubernetes.io/dockerconfigjson - são usados para armazenar credenciais de registro do Docker. Eles são usados para autenticar Pods com um registro do Docker. Eles são montados em Pods que usam imagens de container privadas.
- kubernetes.io/tls, kubernetes.io/ssh-auth e kubernetes.io/basic-auth - são usados para armazenar certificados TLS, chaves SSH e credenciais de autenticação básica, respectivamente. Eles são usados para autenticar Pods com outros serviços.
- bootstrap.kubernetes.io/token - são usados para armazenar tokens de inicialização de cluster. Eles são usados para autenticar nós com o plano de controle do Kubernetes.

Secrets Opaque são armazenados como um mapa de strings, enquanto os Secrets TLS são armazenados como um mapa de strings com chaves adicionais para armazenar certificados e chaves

Base64 não é criptografia, Base64 é um esquema de codificação binária para texto que visa garantir que os dados binários possam ser enviados por canais que são projetados para lidar apenas com texto. Esta codificação ajuda a garantir que os dados permaneçam intactos sem modificação durante o transporte.


----
Para usar o Secret em um Pod, você precisa definir o campo spec.containers[].env[].valueFrom.secretKeyRef

## ConfigMaps

Os ConfigMaps são uma maneira eficiente de desacoplar os parâmetros de configuração das imagens de container. Isso permite que você tenha a mesma imagem de container em diferentes ambientes, como desenvolvimento, teste e produção, com diferentes configurações.

- Atualizações: Os ConfigMaps não são atualizados automaticamente nos pods que os utilizam. Se você atualizar um ConfigMap, os pods existentes não receberão a nova configuração. Para que um pod receba a nova configuração, você precisa recriar o pod.
- Múltiplos ConfigMaps: É possível usar múltiplos ConfigMaps para um único pod. Isso é útil quando você tem diferentes aspectos da configuração que quer manter separados.
- Variáveis de ambiente: Além de montar o ConfigMap em um volume, também é possível usar o ConfigMap para definir variáveis de ambiente para os containers no pod.
- Imutabilidade: A partir da versão 1.19 do Kubernetes, é possível tornar ConfigMaps (e Secrets) imutáveis, o que pode melhorar o desempenho de seu cluster se você tiver muitos ConfigMaps ou Secrets.

## External Secrets Operator

A grande missão do ESO é sincronizar segredos de APIs externas para o ambiente do Kubernetes. 

Considere a utilização do sistema de controle de admissão do Kubernetes (como OPA ou Kyverno) para um controle de acesso mais refinado.

### SecretStore

Imagine o SecretStore como um gerente de segredos que conhece a forma como acessar os dados. Ele contém referências a segredos que mantêm as credenciais para acessar a API externa.

### ExternalSecret

Pense em um ExternalSecret como um pedido feito ao gerente de segredos (SecretStore) para buscar um segredo específico. A configuração do ExternalSecret define o que buscar, onde buscar e como formatar o segredo.

### ClusterSecretStore

O ClusterSecretStore é um SecretStore global, que pode ser referenciado por todos os namespaces. Você pode usá-lo para fornecer um gateway central para seu provedor de segredos. É como um SecretStore, mas com alcance em todo o cluster, ao invés de apenas um namespace.

## Vault

HashiCorp Vault é uma ferramenta para gerenciar segredos de maneira segura

Com o Vault, você pode centralizar a gestão de segredos, reduzindo a superfície de ataque e minimizando o risco de vazamento de dados. O Vault também oferece controle detalhado de políticas de acesso, permitindo determinar quem pode acessar o que, quando e onde.

### Install

```bash
wget -O- https://apt.releases.hashicorp.com/gpg | sudo gpg --dearmor -o /usr/share/keyrings/hashicorp-archive-keyring.gpg

echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] https://apt.releases.hashicorp.com $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/hashicorp.list

sudo apt update && sudo apt install vault
```

#### Install and configure vault

```bash
helm repo add hashicorp https://helm.releases.hashicorp.com
helm install vault hashicorp/vault


kubectl exec -ti vault-0 -- sh

vault operator init
vault operator unseal
vault login

vault policy write external-secret-operator-policy -<<EOF
path "data/postgres" { 
capabilities = ["read"]
}
EOF

vault token create -policy="external-secret-operator-policy"
vault secrets enable -path=data kv
vault kv put data/postgres POSTGRES_USER=admin POSTGRES_PASSWORD=123456


helm repo add external-secrets https://charts.external-secrets.io
helm  repo update
helm install external-secrets external-secrets/external-secrets -n external-secrets --create-namespace --set installCRDs=true
k create secret generic vault-token --from-literal=token=SEU_TOKEN_DO_VAULT
```
