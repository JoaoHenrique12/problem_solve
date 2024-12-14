#include<stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<omp.h>
#define MAX (long long) 1e6

int main(int argc, char *argv[])
{
  /* int* vet = malloc(MAX * sizeof(int)); */
  char vet[MAX];
  srand(123);
  for (size_t i = 0; i < MAX; i++) {
    vet[i] = rand() % 4;
  }
  int aparicoes = 0, n=1;

  /* #pragma omp for */
  /* #pragma omp parallel for reduction(+:aparicoes) */
  for (size_t i = 0; i < MAX; i++) {
    /* #pragma omp critical */
    if(vet[i] == n)
      aparicoes++;
  }

  printf("(n, aparicoes):(%d, %d)\n",n, aparicoes);

  return EXIT_SUCCESS;
}
