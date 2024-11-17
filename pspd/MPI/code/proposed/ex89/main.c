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
  int chunck = VEC_SIZE/(world_size - 1);
  int rest = VEC_SIZE%(world_size - 1);

  if (rank == MASTER) {
    // Allocating info
    vec = malloc(sizeof(vec) * VEC_SIZE);
    for (size_t i = 0; i < VEC_SIZE; i++) 
      { vec[i] = 000 + i; }

    // Sending info
    int tmp_chunck = chunck;
    for ( size_t position = 0, worker_rank = 1; worker_rank < world_size;
        position+= chunck, worker_rank++
    ){ 
      if(worker_rank == world_size - 1)
        tmp_chunck += rest;
      MPI_Send(&vec[position], tmp_chunck, MPI_INT, worker_rank, TAG, MPI_COMM_WORLD);
    }

    // Retrieving info
    MPI_Status st;
    float avg_sum;
    float tmp;
    for (size_t worker_rank = 1; worker_rank < world_size; worker_rank++){ 
      MPI_Recv(&tmp, 1, MPI_FLOAT, MPI_ANY_SOURCE, TAG, MPI_COMM_WORLD, &st);
      avg_sum += tmp;
      printf("avg from %d/%d == %.2f\n", st.MPI_SOURCE, world_size, tmp);
    }
    avg_sum /= (world_size-1);
    printf("avg of avg %d/%d %.4f\n",MASTER, world_size,  avg_sum);
  }
  else {
    if( rank == world_size - 1)
      chunck += rest;
    vec = malloc(sizeof(vec) * chunck);
    MPI_Recv(vec, chunck, MPI_INT, MASTER, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    float sum = 0;
    for (size_t i = 0; i < chunck; i++) { 
      sum += vec[i];
      /* printf("%d/%d vec[%ld]: %d, divide by: %d\n", rank, world_size, i, vec[i], chunck); */
    }

    float avg = sum/chunck;
    MPI_Send(&avg, 1, MPI_FLOAT, MASTER, TAG, MPI_COMM_WORLD);
  }

  free(vec);

  MPI_Finalize();
  return 0;
}
