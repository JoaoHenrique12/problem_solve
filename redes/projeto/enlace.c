#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>

#define MAX_MSG 100
#define true 1
#define false 0

typedef struct package {
  int check_sum;
  char msg[MAX_MSG];
  struct sockaddr_in src;
}Package;

#include "client.c"
#include "server.c"

void kick_server(int port);

int main()
{
  int my_port,send_port;
  char ip_send[20];

  printf("Listen on port: ");
  scanf("%d",&my_port);

  kick_server(my_port);

  printf("Send ip: ");
  scanf("%s",ip_send);

  printf("Send port: ");
  scanf("%d",&send_port);


  return 0;
}

void kick_server(int port)
{
  int sd;
  Package pkg;

  bind_server(&sd,port);
  while(true)
  {
    listen_server(sd,&pkg);
    printf("%s|%d|>'%s'\n",inet_ntoa(pkg.src.sin_addr),pkg.check_sum,pkg.msg);
  }
}
