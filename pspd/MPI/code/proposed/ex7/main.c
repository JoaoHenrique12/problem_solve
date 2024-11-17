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
  vec = (int*) malloc(sizeof(int) * VEC_SIZE);
  if (rank == MASTER) {
    // Allocating info
    for (size_t i = 0; i < VEC_SIZE; i++) 
      { vec[i] = 1000 + (i + 1) * (i + 1); }
  }
  MPI_Bcast(vec, VEC_SIZE, MPI_INT, MASTER, MPI_COMM_WORLD);

  for (int i = 0; i < VEC_SIZE; i++) 
    { printf("%d/%d -> %d\n", rank, world_size, vec[i]); }

  free(vec);

  MPI_Finalize();
  return 0;
}
