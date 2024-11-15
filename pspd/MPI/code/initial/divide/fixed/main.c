#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#define MAX 8
#define MASTER 0
/* Vetor de tamanho fixo (8 posições) compartilhado entre 2 processos.
   Cada um realiza impressão de parte do vetor por ajuste dos índices do vetor*/

int main(int argc, char *argv[]) {
	int rank, nprocs;
	int v[MAX]={10, 20, 30, 40, 50, 60, 70, 80};
	char host[20];
	int ini, fim;
	gethostname(host, 19);
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	if (rank == MASTER) {
		ini = 0;
		fim = 4; }
	else {
		ini = 4;
		fim = 8;
	} /* fim-if */

	printf("Host %s, Processo %d/%d: ", host, rank, nprocs);
	for (int i=ini; i<fim; i++)
		printf("%d ", v[i]);
	printf("\n");
	MPI_Finalize();
	return 0;
}/* fim-main */
