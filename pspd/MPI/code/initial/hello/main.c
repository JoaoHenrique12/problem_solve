#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
  MPI_Init(NULL, NULL);

  // get world size
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Get rank of process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // Get name of processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  printf("(world_size, name, rank): (%d, %s, %d)\n", world_size,processor_name, world_rank);

  MPI_Finalize();
  return 0;
}
