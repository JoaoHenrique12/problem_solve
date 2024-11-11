# RPC

## Teoria

RPC -> Remote Procedure Call

### XDR

Ou seja, a capacidade de fazer com que funções possam ser escritas entre hosts que possuem diferentes
representações internas para números (inteiro, real, etc.) e caracteres seja viabilizado.

Little endian, Big endian ?

Para resolver essa questão de representação de dados entre hosts distintos existe uma biblioteca associada à biblioteca RPC denominada XDR (eXternal Data Representation)

Tipos de dados em RPC, são pré definidos.
- Counted array (limite superior fixo, mas arrays individuais podem variar no tamanho)
- Fixed array (array fixo)
- Structure
- Optional Data (pode nao ser passado)

Funções de conversão entre dados comuns para os da XDR.
  - Xdr_pointer, Um ponteiro (usado em listas encadeadas ou árvores)
  - Xdr_opaque, sem conversão
  - Xdr_vector, array fixo

### Find server

Um cliente rpc encontra um server rpc atraves de perguntas para uma directory machine, e depois pergunta para um daemon aonde esta
a funcao chamada.

O serviço de diretórios então é um pré-requisito para viabilizar aplicações RPC. **portmapper**
  - É um servidor que converte números de programa RPC em números de portas disponíveis no protocolo TCP/IP.

## Info

```bash
# env vars to compile
export LDLIBS="$LDLIBS -ltirpc"
export CFLAGS="$CFLAGS -I/usr/include/tirpc"
```

```bash
sudo apt install rpcbind
# validate if it is working
rpcinfo -p 
```

```bash
# gerenciamento de memoria
rpcgen –c –N text.x > text_xdr.c
```

## sample

Add file [calcula.x](./calcula/calcula.x)

```bash
rpcgen -a calcula.x
```

Edit only files: 
  - [calcula_client.c](./calcula/calcula_client.c) 
  - [calcula_server.c](./calcula/calcula_server.c)

## Tips

procure não usar xdr_string, mas sim xdr_wrapstring.

semântica “least once” (pelo menos uma vez)
