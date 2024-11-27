#include <mpi.h>

#include <stdio.h>
#include<stdlib.h>

#include<sys/time.h>
#include<unistd.h>

#define		MASTER	0
#define		TAG	0
#define   MAX 100
#define   STOP -1

int main() {
	int rank, nprocs;

  char texto_base[] = "abcdefghijklmnopqrstuvwxyz 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  struct timeval tv;

  int number, tmp_index, i;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	//          cont, indice
	int token[2] = {0,0};
	if (rank == MASTER) {
		MPI_Send(token, 2, MPI_INT, 1, TAG, MPI_COMM_WORLD);
	}

	int rank_back = ((rank-1) + nprocs) % nprocs;
	int rank_nxt = (rank+1) % nprocs;

	while (token[0] != STOP) {
		MPI_Recv(token, 2, MPI_INT, rank_back, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (token[0] != STOP){
    	gettimeofday(&tv, NULL);
    	number = ((tv.tv_usec/47) % 3) + 1;
    	tmp_index = token[1];
    	for(i = 0; i < number; i++)
      	if(!(tmp_index + i > sizeof(texto_base)))
        	fprintf(stderr, "%c", texto_base[tmp_index + i]);
    	token[1] = tmp_index + i;

    	if(tmp_index + i > sizeof(texto_base)){
      	fprintf(stderr,"\n");
      	token[1] = 0;
    	}
			token[0]++; 
		}
		if(token[0] >= MAX ) token[0] = STOP;
		// A pesar do programa imprimir colaborativamente e fprintf na stderr já fazer o flush da mensagem, 
		// o texto ainda saia desorganizado. Com este usleep(1) ele organiza a saida perfeitamente.
		// A principal diferença deste programa para os anteriores é que o token daqui representa 2 variáveis
		// do programa original: token[0] == cont e token[1] é o indice.
		//
		// O esquema de colaboração round-robin/token-ring daqui é idêntico ao dos exercícios anteriores.
		usleep(1); 
		MPI_Send(token, 2, MPI_INT, rank_nxt, TAG, MPI_COMM_WORLD);
	}
	if (rank == MASTER) 
  	fprintf(stderr,"\n");

	MPI_Finalize();
	return 0;
}
