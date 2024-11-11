# MPI

Message-Passing-Interface

## Tools

### Install

```bash
sudo apt install mpich
```

### Compile code

```bash
mpicc main.c
mpirun -np <numero_processos> ./a.out
```
[sample](./hello_mpi/main.c)

[data types](https://www.mpich.org/static/docs/v3.3/www3/Constants.html)

## Apostila

### Message-Parsing

- Conjunto de processos que possuem acesso à memória local
- Comunicação dos processos baseados no envio e recebimento de mensagens;
- A transferência de dados entre processos requer operações de cooperação entre cada processo
(uma operação de envio deve "casar" com uma operação de recebimento).
- Fine-Grain
- Coarse-Grain

- Comunicação Point to Point (Send-Receive);
  - Blocking(send, receive)
  - NonBlocking
- Comunicação Coletiva: Broadcast, Scatter, Gather, Collective Computations (Reduction).
  - Sincronizacao
  - Envio de dados
  - Computacao coletiva


#### Componentes comuns entre as bibliotecas

- Gerência de processos: iniciar, finalizar, determinar o número de processos, identificar processos, etc;
- Comunicação "Point-to-Point": Enviar e receber mensagens entre dois processos;
- Comunicação coletiva: "broadcast", “scatter”, “gatter”, “reduce” e sincronizar processos.

#### Buffers

- Existem buffers, coisas sincronizadas perfeitamente sao raras.
- Transparente para o programador e gerenciado pelo MPI

#### Blocking

- Blocking send, termina após o buffer da aplicação (variável), estiver seguro e liberado para uso. Modificação no buffer,
não irá afetar o dado transmitido, não implica que o dado já tenha sido recebido;
- Blocking send, sincrono existe uma comunicação ocorrendo com o processo que recebe, com confirmação da transmissão da mensagem
pelo processo que recebe;
- Blocking send,  assíncrono, o que significa que o system buffer está sendo utilizado para armazenar uma mensagem para ser enviada;
- Blocking receive só retorna a execução após a mensagem ter chegado, e estar pronta para ser utilizada pelo programa.

#### NonBlocking

- Não é seguro modificar o valor do buffer de aplicação, até que se saiba que a operação non_blocking tenha sido executada pela biblioteca MPI;
- Utilizadas para evitar problemas de comunicação (“deadlock”) e melhorar a performance. 

#### Sincrono

Comunicação na qual o processo que envia a mensagem, não retorna a execução normal, enquanto
não haja um sinal do recebimento da mensagem pelo destinatário;

#### Assincrono

Comunicação na qual o processo que envia a mensagem, não espera que haja um sinal de recebimento
da mensagem pelo destinatário

#### Overhead

- System overhead
- Syncronization overhead

### Conceitos e Definicoes

- rank: id do processo, comeca em 0 e vai ate n - 1
- group: conjunto ordenado de N processos. Todo e qualquer grupo é associado a um "communicator" e, inicialmente, todos os processos são menbros de um grupo com um
  "communicator" já pré-estabelecido (MPI_COMM_WORLD).
- communicator: define uma coleção de processos (grupo), que poderão se comunicar entre si (contexto).
- aplication buffer 
- system buffer
- blocking communication
- nonblocking communication
- standard send
- syncronous send
- buffered send
- ready send
- standard receive
- return code
