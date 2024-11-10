#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

int main(int argc, char *argv[])
{
  int list_size, *l;
  if (argc < 2) 
  {
    printf("error, right way to use is %s num1, num2, num3...\n", argv[0]);
    exit(1);
  }

  list_size = argc - 1;
  l = (int*) malloc(sizeof(int) * list_size);

  for (int i = 0; i < list_size; i++) 
    { l[i] = atoi(argv[i + 1]); }

  print_sum(l, list_size);

  return 0;
}
