#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

int main(int argc, char *argv[])
{
  int list_size, i;
  Lista *lst, *begin, *aux;

  if (argc < 2) {
    printf("error, right way to use is %s num1, num2, num3...\n", argv[0]);
    exit(1);
  }

  list_size = argc - 1;
  begin = (Lista*) malloc(sizeof(Lista));
  lst = begin;
  for (int i = 0; i < list_size; i++) {
    lst->value = atoi(argv[i + 1]);
    lst->nxt = (Lista*) malloc(sizeof(Lista)); 

    aux = lst;
    lst = lst->nxt;
  }

  free(aux->nxt);
  aux->nxt = NULL;

  print_list(begin);
  print_sum(begin);

  return 0;
}
