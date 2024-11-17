# Comunicação coletiva

## Broadcast

Espalha a mesma informação

A ->    A
        A
        A

```c
int MPI_Bcast(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
               void *recvbuf, int recvcount, MPI_Datatype recvtype,
               int root, MPI_Comm comm)
```

## Scatter

Espalha informação

A B C ->   A
           B
           C

```c
// 3 variaveis para enviar
// 3 variaveis para receber
// 2 de controle
//   1 root
//   1 communicator
int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
               void *recvbuf, int recvcount, MPI_Datatype recvtype,
               int root, MPI_Comm comm)
```

## Gather

Faz a operação inversa que o Scatter faz.


A B C <-   A
           B
           C
```c
// 3 variaveis para enviar
// 3 variaveis para receber
// 2 de controle
//   1 root
//   1 communicator
int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
               void *recvbuf, int recvcount, MPI_Datatype recvtype,
               int root, MPI_Comm comm)
```

## Reduce

Recupera elementos e aplica uma operação pré definida.

A op B op C  <-  A
                 B
                 C

```c
// No caso listado a cima o count e 1
// 
int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)

/* typedef enum _MPI_Op {  */
/*   MPI_OP_NULL  = 0x18000000, */
/*   MPI_MAX      = 0x58000001, */
/*   MPI_MIN      = 0x58000003, */
/*   MPI_SUM      = 0x58000003, */
/*   MPI_PROD     = 0x58000004, */
/*   MPI_LAND     = 0x58000005, */
/*   MPI_BAND     = 0x58000006, */
/*   MPI_LOR      = 0x58000007, */
/*   MPI_BOR      = 0x58000008, */
/*   MPI_LXOR     = 0x58000009, */
/*   MPI_BXOR     = 0x5800000a, */
/*   MPI_MINLOC   = 0x5800000b, */
/*   MPI_MAXLOC   = 0x5800000c, */
/*   MPI_REPLACE  = 0x5800000d */
/* } MPI_Op; */
```
