#include<string.h>
#include<stdlib.h>

#ifndef UTILS_C
#define UTILS_C

#define MAX_MSG 100
#define true 1
#define false 0
#define bool short

typedef struct package {
  int check_sum;
  char msg[MAX_MSG];
  struct sockaddr_in src;
}Package;


int make_hash(char* msg)
{
  int hash = 0;

  for(int i = 0; i < strlen(msg);i++ )
    hash += msg[i] * (i + 1) * (i + 1);

  return hash;
}

bool validation_package(Package* pkg)
{
  return make_hash(pkg->msg) == pkg->check_sum;
}

bool violate_package(Package* pkg)
{
  bool kick_package = rand() % 2;

  if( kick_package )
    strncpy(pkg->msg,"TRUCO",6);

  return kick_package;
}

#endif
