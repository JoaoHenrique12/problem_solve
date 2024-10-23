/***********************************/
/* FGA/EngSofware/FRC  udpClient.c */
/* Prof. Fernando W Cruz           */
/***********************************/
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset() */
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_MSG 100

int main(int argc, char *argv[]) {
  int sd, rc, i;
  struct sockaddr_in ladoCli;  /* dados do cliente local   */
  struct sockaddr_in ladoServ; /* dados do servidor remoto */

  /* confere o numero de argumentos passados para o programa */
  if (argc < 3) {
    printf("uso correto: %s <ip_do_servidor> <porta_do_servidor> <dado1> ... "
           "<dadoN> \n",
           argv[0]);
    exit(1);
  }

  /* Preenchendo as informacoes de identificacao do remoto */
  ladoServ.sin_family = AF_INET;
  ladoServ.sin_addr.s_addr = inet_addr(argv[1]);
  ladoServ.sin_port = htons(atoi(argv[2]));

  /* Preenchendo as informacoes de identificacao do cliente */
  ladoCli.sin_family = AF_INET;
  ladoCli.sin_addr.s_addr = htonl(INADDR_ANY);
  ladoCli.sin_port = htons(0); /* usa porta livre entre (1024-5000)*/

  /* Criando um socket. Nesse momento a variavel       */
  /* sd contem apenas dados sobre familia e protocolo  */

  sd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sd < 0) {
    printf("%s: n�o pode abrir o socket \n", argv[0]);
    exit(1);
  }

  /* Relacionando o socket sd com a estrutura ladoCli */
  /* Depois do bind, sd faz referencia a protocolo local, ip local e porta local
   */
  rc = bind(sd, (struct sockaddr *)&ladoCli, sizeof(ladoCli));
  if (rc < 0) {
    printf("%s: n�o pode fazer um bind da porta\n", argv[0]);
    exit(1);
  }
  printf("[UDP, client:(%s, %u), server:(%s, %s)]\n",
         inet_ntoa(ladoCli.sin_addr), ntohs(ladoCli.sin_port), argv[1],
         argv[2]);

  /* Enviando um pacote para cada parametro informado */
  for (i = 3; i < argc; i++) {
    if (strlen(argv[i]) > MAX_MSG) {
      printf("Message could not exceed MAX_MSG %d", MAX_MSG);
      exit(1);
    }
    rc = sendto(sd, argv[i], strlen(argv[i]), 0, (struct sockaddr *)&ladoServ,
                sizeof(ladoServ));
    if (rc < 0) {
      printf("%s: nao pode enviar dados %d \n", argv[0], i - 1);
      close(sd);
      exit(1);
    }
    printf("Enviando parametro %d: %s\n", i - 2, argv[i]);
  }
  return 0;
}
