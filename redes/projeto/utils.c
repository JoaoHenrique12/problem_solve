#include<string.h>

#ifndef UTILS_C
#define UTILS_C

#define MAX_MSG 100
#define true 1
#define false 0

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
#endif
