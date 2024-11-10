#include <stdio.h>
#include "utils.h"

void print_list(Lista* l)
{
  while (l) {
    printf("%d ", l->value);
    l = l->nxt;
  }
  printf("\n");
}

void print_sum(Lista* l)
{
  int sum = 0;
  while (l) {
    sum += l->value;
    l = l->nxt;
  }
  printf("sum: %d\n", sum);
}
