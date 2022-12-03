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

void bind_server(int* sd, int port)
{
  struct sockaddr_in	endServ;

  endServ.sin_family 	  = AF_INET;
  endServ.sin_addr.s_addr = htonl(INADDR_ANY); 
  endServ.sin_port 	  = htons(port);
  *sd = socket(AF_INET, SOCK_DGRAM, 0);

  if(*sd<0) 
    { printf("Nao pode abrir o socket \n"); exit(1);  }

/* Fazendo um bind na porta local do servidor */
  int rc = bind (*sd,(struct sockaddr*) &endServ, sizeof(endServ));
  if(rc<0) 
    { printf("Nao pode fazer bind na porta %d\n",port); exit(1); }

  printf("Esperando por dados no IP: 127.0.0.1, porta UDP numero: %d \n",port);

}

void listen_server(int sd,char* msg)
{
  socklen_t		tam_Cli;
  struct sockaddr_in	endCli;

  memset(msg,0x0,MAX_MSG);
  tam_Cli = sizeof(endCli);
  
  int n = recvfrom(sd, msg, MAX_MSG, 0, (struct sockaddr *) &endCli, &tam_Cli);
  if(n<0) 
    { printf("Nao pode receber dados \n"); return;} 
    
  return;
}

int main() {
  int	sd;

  bind_server(&sd,3030);

  char msg[MAX_MSG];

  while(1)
  {
    listen_server(sd,msg);
    printf("Mensagem na main:%s\n",msg);
  }

  return 0;
}
