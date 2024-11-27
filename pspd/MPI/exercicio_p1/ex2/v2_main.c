#include <stdio.h>
#include <mpi.h>
#define		MASTER	0
#define		TAG	0
#define   MAX 10
#define   STOP -1

int main() {
	int rank, nprocs;
	int token = 0;

	int vec[MAX];

	for (size_t i = 0; i < MAX; i++) {
		vec[i] = i * 2;
	}

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	if (rank == MASTER) {
		printf("Generating first message\n");
		MPI_Send(&token, 1, MPI_INT, 1, TAG, MPI_COMM_WORLD);
	}

	int rank_back = ((rank-1) + nprocs) % nprocs;
	int rank_nxt = (rank+1) % nprocs;

	while (token != STOP) {
		MPI_Recv(&token, 1, MPI_INT, rank_back, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (token != STOP){ printf("%d/%d printa numeros [%d, %d]\n", rank, nprocs, vec[token], vec[token + 1]); token+=2; }
		if(token >= MAX ) token = STOP;
		MPI_Send(&token, 1, MPI_INT, rank_nxt, TAG, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}
