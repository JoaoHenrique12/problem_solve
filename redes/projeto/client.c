/***********************************/
/* FGA/EngSofware/FRC  udpClient.c */
/* Prof. Fernando W Cruz           */
/***********************************/ 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG 100

int sd, rc, i;
struct sockaddr_in ladoCli;
struct sockaddr_in ladoServ;

// IP PORTA MENSAGEM
void start_client()
{
  /* Preenchendo as informacoes de identificacao do servidor */
  ladoServ.sin_family 	   = AF_INET;
  ladoServ.sin_addr.s_addr = inet_addr("127.0.0.1");
  ladoServ.sin_port 	   = htons(3030);

  /* Preenchendo as informacoes de identificacao do cliente */
  ladoCli.sin_family 	 = AF_INET;
  ladoCli.sin_addr.s_addr= htonl(INADDR_ANY);  
  ladoCli.sin_port 	     = htons(0); /* usa porta livre entre (1024-5000)*/

  /* sd contem apenas dados sobre familia e protocolo  */

  sd = socket(AF_INET,SOCK_DGRAM,0);
  if(sd<0) 
    { printf("Nao pode abrir o socket \n"); exit(1); }

  /* Relacionando o socket sd com a estrutura ladoCli */
  /* Depois do bind, sd faz referencia a protocolo local, ip local e porta local */
  rc = bind(sd, (struct sockaddr *) &ladoCli, sizeof(ladoCli));
  if(rc<0) 
    { printf("Nao pode fazer um bind da porta\n"); exit(1); }
  printf("{UDP, IP_Cli: %s, Porta_Cli: %u, IP_R: %s, Porta_R: %d}\n", inet_ntoa(ladoCli.sin_addr), ntohs(ladoCli.sin_port), "127.0.0.1", 3030);
}

void send_server()
{
  char msg[MAX_MSG];
  scanf("%s",msg);

  rc = sendto(sd, msg, strlen(msg), 0,(struct sockaddr *) &ladoServ, sizeof(ladoServ));
  if(rc<0) 
    { printf("Nao pode enviar os dados.\n"); close(sd); exit(1); }
  printf("Enviando mensagem:%s\n",msg);
}

int main() {
  start_client();
  send_server();

  return 0;
}
