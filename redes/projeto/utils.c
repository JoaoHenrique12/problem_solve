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

#endif
