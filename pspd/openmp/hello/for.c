#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <string.h>
#define MAX 10

int main(int argc, char *argv[])
{
  int vet[omp_get_max_threads()];
  memset(vet, 0, 4* omp_get_max_threads());

  #pragma omp parallel for
  for (int i = 0; i < 10; i++)
    vet[omp_get_thread_num()]++;

  for(int i = 0; i < omp_get_max_threads(); i++)
    printf("%d executed %d\n", i, vet[i]);
  return EXIT_SUCCESS;
}
