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

void listen_server(int sd,Package* pkg)
{
  socklen_t		tam_Cli;
  struct sockaddr_in	endCli;

  memset(pkg->msg,'T',MAX_MSG);
  tam_Cli = sizeof(endCli);
  
  int n = recvfrom(sd, pkg, sizeof(Package), 0, (struct sockaddr *) &pkg->src, &tam_Cli);
  if(n<0) 
    printf("Nao pode receber dados \n"); 
    
  return;
}
