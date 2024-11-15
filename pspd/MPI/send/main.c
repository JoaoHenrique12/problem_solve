#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <mpi.h>
#define	MASTER 	0
#define TAG	0
#define	MAX	1000
int main() {
	int 		rank, nprocs;
	char 		msg[100];
	char		host[20];
	MPI_Status	st;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	if (rank == MASTER) {
		for (int i = 1; i < nprocs; i++) {
			MPI_Recv(msg, 100, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
			printf("Processo %d/%d enviou: %s\n", st.MPI_SOURCE, nprocs, msg);
		}
	} else {
		gethostname(host, 19);
		sprintf(msg, "Hi, MASTER! I'm alive, running on %s and sending %d value!", host, MAX+rank);
		MPI_Send(msg, strlen(msg), MPI_CHAR, MASTER, TAG, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
