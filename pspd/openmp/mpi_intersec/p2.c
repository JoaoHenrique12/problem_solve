#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<mpi.h>
#define MAX 100000
#define ROOT 0
#define TAG 0

int list[MAX];

int main(){
  MPI_Init(NULL, NULL);
  int rank, nprocs;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);


  // READ
  int omp_procs, list_size;

  if(rank == ROOT) {
    scanf("%d",&omp_procs);
    scanf("%d",&list_size);

    for(int i = 0; i < list_size; i++)
      scanf("%d", &list[i]);
    for(int i = 1; i < nprocs; i++)
    {
      MPI_Send(&list_size, 1, MPI_INT, i, TAG, MPI_COMM_WORLD);
      MPI_Send(list, list_size, MPI_INT, i, TAG, MPI_COMM_WORLD);
    }
  } else {
    MPI_Recv(&list_size, 1, MPI_INT, ROOT, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(list, list_size, MPI_INT, ROOT, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  // Divide for MPI
  int ini, fim, chunck;

  chunck = list_size/nprocs;

  ini = rank * chunck;
  fim = ini + chunck;

  if(rank == nprocs - 1)
    fim += list_size%nprocs;

  int final_sum = 0;


  // Partial Sum, including master

  int partial_sum = 0;
  #pragma omp parallel for
  for(int i = ini; i < fim; i++)
  {
    #pragma omp atomic
    partial_sum += list[i];
  }

  MPI_Send(&partial_sum, 1, MPI_INT, ROOT, TAG, MPI_COMM_WORLD);

  if(rank == ROOT)
  {
    int tmp;
    for(int i = 0; i < nprocs; i++)
    {
      MPI_Recv(&tmp, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      final_sum+= tmp;
    }
    printf("Final sum is %d\n", final_sum);
  }

  MPI_Finalize();
  return 0;
}
