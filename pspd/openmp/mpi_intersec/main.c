#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<mpi.h>

int main(int argc, char *argv[])
{
  int rank, nprocs;
  omp_set_num_threads(3);

  MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

  int tid, sub_n;
  #pragma omp parallel
  {
    tid = omp_get_thread_num();
    sub_n = omp_get_num_threads();
    printf("(rank, nprocs, tid, sub_n), (%d, %d, %d, %d)\n", rank, nprocs, tid, sub_n);
  }

  MPI_Finalize();
  return EXIT_SUCCESS;
}
