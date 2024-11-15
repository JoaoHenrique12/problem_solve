# Scatter

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
