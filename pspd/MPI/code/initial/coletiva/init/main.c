#include <stdio.h>
#include <unistd.h>
#include <mpi.h>
#define MASTER 0
#define TAG 0
/* Aqui o MASTER espalha elementos do vetor para os processos, e o MASTER fica com o 1o.elemento 
   Perceber que a declaração do vetor precisa ser feita em todos os processos, já que ele
   é usado em MPI_Scatter, que é chamado em todos os processos. Isso não é
   muito produtivo... (se fosse um vetor grande, não economizaria muito...)
*/
int main(int argc, char *argv[]) {
	int rank, nprocs;
	char maquina[20];
	int dados[4], dado_recebido;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	gethostname(maquina, 19);
	if (rank == MASTER) {
		dados[0] = 39;
		dados[1] = 42;
		dados[2] = 75;
		dados[3] = 128;
	}
	MPI_Scatter(dados, 1, MPI_INT, &dado_recebido, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
	printf("Host %s, Processo %d/%d imprimiu valor %d\n", maquina, rank, nprocs, dado_recebido);
	MPI_Finalize();
	return 0;
} /* fim-main */
