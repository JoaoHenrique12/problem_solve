/* Esse código forma um anel de processos com execução serial, controlada por um token
  que é gerado pelo MASTER e passado para cada um até retornar de volta ao MASTER
*/
#include <stdio.h>
#include <mpi.h>
#define		MASTER	0
#define		TAG	0

int main() {
	int rank, nprocs;
	int token =1;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	if (rank == MASTER) {
		printf("%d enviando token para o processo %d\n", rank, rank+1);
		MPI_Send(&token, 1, MPI_INT, 1, TAG, MPI_COMM_WORLD);
		MPI_Recv(&token, 1, MPI_INT, nprocs-1, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	} else { /* demais processos (slaves) */
		MPI_Recv(&token, 1, MPI_INT, rank-1, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("%d enviando token para o processo %d\n", rank, (rank+1)%nprocs);
		MPI_Send(&token, 1, MPI_INT, (rank+1)%nprocs, TAG, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
