/* *****************************/
/* FGA / Eng. Software / FRC   */
/* Prof. Fernando W. Cruz      */
/* Codigo: tcpServer conc.c    */
/* *****************************/
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define QLEN 5      /* tamanho da fila de clientes  */
#define MAX_SIZE 80 /* tamanho do buffer */

void atende_cliente(int descritor, struct sockaddr_in endCli);

int main(int argc, char *argv[]) {
  struct sockaddr_in endServ;
  struct sockaddr_in endCli;
  int sd, novo_sd;
  int pid, n;
  unsigned int alen;

  if (argc < 3) {
    printf("Digite IP e Porta para este servidor\n");
    exit(1);
  }
  memset((char *)&endServ, 0, sizeof(endServ));
  endServ.sin_family = AF_INET;
  endServ.sin_addr.s_addr = inet_addr(argv[1]);
  endServ.sin_port = htons(atoi(argv[2]));

  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0) {
    fprintf(stderr, "Falha ao criar socket!\n");
    exit(1);
  }

  if (bind(sd, (struct sockaddr *)&endServ, sizeof(endServ)) < 0) {
    fprintf(stderr, "Ligacao Falhou!\n");
    exit(1);
  }

  if (listen(sd, QLEN) < 0) {
    fprintf(stderr, "Falhou ouvindo porta!\n");
    exit(1);
  }

  printf("Servidor ouvindo no IP %s, na porta %s ...\n\n", argv[1], argv[2]);
  /* Aceita conexoes */
  alen = sizeof(endCli);
  while (1) {
    /* espera nova conexao de um processo cliente ... */
    if ((novo_sd = accept(sd, (struct sockaddr *)&endCli, &alen)) < 0) {
      fprintf(stdout, "Falha na conexao\n");
      exit(1);
    }
    pid = fork();
    if (pid < 0)
      fprintf(stdout, "Falha na criacao do processo filho!\n");
    else if (pid == 0) { /* processo filho */
      close(sd);         /* encerra o socket sd */
      fprintf(stdout, "Cliente %s: %u conectado.\n", inet_ntoa(endCli.sin_addr),
              ntohs(endCli.sin_port));
      atende_cliente(novo_sd, endCli);
      exit(0);
    }
    close(novo_sd);
  }
}

void atende_cliente(int descritor, struct sockaddr_in endCli) {
  char bufin[MAX_SIZE];
  int n;
  while (1) {
    memset(&bufin, 0x0, sizeof(bufin));
    n = recv(descritor, &bufin, sizeof(bufin), 0);
    if (strncmp(bufin, "FIM", 3) == 0)
      break;
    fprintf(stdout, "[%s:%u] => %s\n", inet_ntoa(endCli.sin_addr),
            ntohs(endCli.sin_port), bufin);
  }
  fprintf(stdout, "Encerrando conexao com %s:%u ...\n",
          inet_ntoa(endCli.sin_addr), ntohs(endCli.sin_port));
  close(descritor);
}
