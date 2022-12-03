/****************************************/
/* FGA/EngSofrware/FRC - udpServer.c    */
/* Prof. Fernando W. Cruz               */
/****************************************/ 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h> /* close() */
#include <string.h>
#include <stdlib.h>

#define MAX_MSG 100

int			sd, rc, n;
socklen_t		tam_Cli;
struct sockaddr_in	endCli;
struct sockaddr_in	endServ;
char			msg[MAX_MSG];


void start_server()
{
  sd=socket(AF_INET, SOCK_DGRAM, 0);
  if(sd<0) 
    { printf("Nao pode abrir o socket \n"); exit(1);  }

/* Preenchendo informacoes sobre o servidor */
  endServ.sin_family 	  = AF_INET;
  endServ.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  endServ.sin_port 	  = htons(3030);

/* Fazendo um bind na porta local do servidor */
  rc = bind (sd, (struct sockaddr *) &endServ,sizeof(endServ));
  if(rc<0) 
    { printf("Nao pode fazer bind na porta 3030 \n"); exit(1); }

  printf("Esperando por dados no IP: 127.0.0.1, porta UDP numero: 3030 \n");

}

void listen_server()
{
  memset(msg,0x0,MAX_MSG);
  tam_Cli = sizeof(endCli);
  
  n = recvfrom(sd, msg, MAX_MSG, 0, (struct sockaddr *) &endCli, &tam_Cli);
  if(n<0) 
    { printf("Nao pode receber dados \n"); return;} 
    
  printf("{UDP, IP_L: %s, Porta_L: %u", inet_ntoa(endServ.sin_addr), ntohs(endServ.sin_port));
  printf(" IP_R: %s, Porta_R: %u} => %s\n",inet_ntoa(endCli.sin_addr), ntohs(endCli.sin_port), msg);
}

int main() {
  start_server();

  while(1)
  {
    listen_server();
  }

  return 0;
}
