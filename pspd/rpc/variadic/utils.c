#include <stdio.h>
#include "utils.h"

void print_sum(int* l, int n)
{
  int sum = 0, i = 0;
  while (i < n) {
    sum += l[i];
    i++;
  }
  printf("sum: %d\n", sum);
}
