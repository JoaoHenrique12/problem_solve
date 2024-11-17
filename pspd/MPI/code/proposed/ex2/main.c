#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define MASTER 0
#define TAG 0


int main(int argc, char *argv[])
{
  MPI_Init(NULL, NULL);

  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  int* vec;
  int rtr;
  if (rank == MASTER)
  {
    vec = malloc(sizeof(vec) * world_size);
    for (size_t i = 0; i < world_size; i++) 
      { vec[i] = 1000 + (i + 1) * (i + 1); }
  }
  MPI_Scatter(vec, 1, MPI_INT,
              &rtr, 1, MPI_INT,
              MASTER, MPI_COMM_WORLD);

  printf("rank %d/%d -> print(%d)\n", rank, world_size, rtr);

  MPI_Finalize();
  return 0;
}
