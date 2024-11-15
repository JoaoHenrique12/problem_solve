#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#define MAX 8
#define MASTER 0

/* Vetor de tamanho fixo, compartilhado entre número aleatório de processos */
int main(int argc, char *argv[]) {
	int rank, nprocs;
	int v[MAX]={10, 20, 30, 40, 50, 60, 70, 80};
	char host[20];
	int chunk;
	int ini, fim;
	gethostname(host, 19);
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	chunk = MAX / nprocs;

	ini = rank * chunk;
	fim = ini + chunk;

	if (rank == (nprocs - 1))
		fim += (MAX%nprocs);

	printf("Host %s, Processo %d/%d: ", host, rank, nprocs);
	for (int i=ini; i<fim; i++)
		printf("%d ", v[i]);
	printf("\n");

	MPI_Finalize();
	return 0;
}
