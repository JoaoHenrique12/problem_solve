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

void start_client(int* sd)
{
  struct sockaddr_in ladoCli;

  /* Preenchendo as informacoes de identificacao do cliente */
  ladoCli.sin_family 	 = AF_INET;
  ladoCli.sin_addr.s_addr= htonl(INADDR_ANY);  
  ladoCli.sin_port 	     = htons(0); /* usa porta livre entre (1024-5000)*/

  /* sd contem apenas dados sobre familia e protocolo  */

  *sd = socket(AF_INET,SOCK_DGRAM,0);
  if(*sd<0) 
    { printf("Nao pode abrir o socket \n"); exit(1); }

  /* Relacionando o socket sd com a estrutura ladoCli */
  /* Depois do bind, sd faz referencia a protocolo local, ip local e porta local */
  int rc = bind(*sd, (struct sockaddr *) &ladoCli, sizeof(ladoCli));
  if(rc<0) 
    { printf("Nao pode fazer um bind da porta\n"); exit(1); }
}

void send_server(int sd, char* ip, int porta,Package* pkg)
{
  struct sockaddr_in ladoServ;
  /* Preenchendo as informacoes de identificacao do servidor */
  ladoServ.sin_family 	   = AF_INET;
  ladoServ.sin_addr.s_addr = inet_addr(ip);
  ladoServ.sin_port 	   = htons(porta);

  int rc = sendto(sd, pkg, sizeof(Package), 0,(struct sockaddr *) &ladoServ, sizeof(ladoServ));
  if(rc<0) 
    { printf("Nao pode enviar os dados.\n"); close(sd); exit(1); }

  printf("Enviando mensagem:%s\n",pkg->msg);
}
