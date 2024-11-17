#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define MASTER 0
#define TAG 0

#define VEC_SIZE 8

int main(int argc, char *argv[])
{
  MPI_Init(NULL, NULL);

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  int* vec;
  int chunck = VEC_SIZE/world_size;
  int rest = VEC_SIZE%world_size;

  if (rank == MASTER) {
    // Allocating info
    vec = malloc(sizeof(vec) * VEC_SIZE);
    for (size_t i = 0; i < VEC_SIZE; i++) 
      { vec[i] = 1000 + (i + 1) * (i + 1); }

    // Sending info
    int tmp_chunck = chunck;
    for (size_t position = 0, worker_rank = 0;
        worker_rank < world_size;
        position+= chunck, worker_rank++) 
    { 
      if(worker_rank == world_size - 1)
        tmp_chunck += rest;
      printf("tmp_chunck: %d\n", tmp_chunck);
      MPI_Send(&vec[position], tmp_chunck, MPI_INT, worker_rank, TAG, MPI_COMM_WORLD);
    }
    free(vec);
  }
  if( rank == world_size - 1)
    chunck += rest;

  vec = malloc(sizeof(vec) * chunck);
  MPI_Recv(vec, chunck, MPI_INT, MASTER, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  printf("rank %d/%d printing %d ->", rank, world_size, chunck);
  for (size_t i = 0; i < chunck; i++) {
    printf(" %d", vec[i]);
  }
  printf("\n");

  MPI_Finalize();
  return 0;
}
