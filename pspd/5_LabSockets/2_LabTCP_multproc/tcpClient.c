/* ******************************/
/* FGA/Eng. Software/ FRC       */
/* Prof. Fernando W. Cruz       */
/* Codigo: tcpClient.c          */
/* ******************************/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_SIZE 80

int main(int argc, char *argv[]) {
  struct sockaddr_in ladoServ;
  int sd;
  int n, k;
  char bufout[MAX_SIZE]; /* buffer de dados enviados  */

  if (argc < 3) {
    printf("uso correto: %s <ip_do_servidor> <porta_do_servidor>\n", argv[0]);
    exit(1);
  }

  memset((char *)&ladoServ, 0, sizeof(ladoServ));
  memset((char *)&bufout, 0, sizeof(bufout));

  ladoServ.sin_family = AF_INET;
  ladoServ.sin_addr.s_addr = inet_addr(argv[1]);
  ladoServ.sin_port = htons(atoi(argv[2]));

  /* Cria socket */
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0) {
    fprintf(stderr, "Criacao do socket falhou!\n");
    exit(1);
  }

  /* Conecta socket ao servidor definido */
  if (connect(sd, (struct sockaddr *)&ladoServ, sizeof(ladoServ)) < 0) {
    fprintf(stderr, "Tentativa de conexao falhou!\n");
    exit(1);
  }
  while (1) {
    printf("> ");
    fgets(bufout, MAX_SIZE, stdin);       /* le dados do teclado */
    send(sd, &bufout, strlen(bufout), 0); /* enviando dados ...  */
    if (strncmp(bufout, "FIM", 3) == 0)
      break;
  }
  printf("------- encerrando conexao com o servidor -----\n");
  close(sd);
  return 0;
}
