#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define MAX 1000

int main(int argc, char *argv[])
{
  int vec[MAX], sum = 0;
  for (size_t i = 0; i < MAX; i++) {
    vec[i] = 1;
  }
  #pragma omp parallel for reduction(+:sum)
  for (size_t i = 0; i < MAX; i++) {
    sum += vec[i] ;
  }


  printf("sum: %d\n", sum);
  return EXIT_SUCCESS;
}
