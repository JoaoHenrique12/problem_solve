#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define MAX (int) 1e6

// Dado o arquivo de 1e6 linhas, encontre quantas vezes o numero 23 apareceu nele ?
// ans: 10023
// a versao paralela fica pior.

int main(int argc, char *argv[])
{
  int aparicoes_23 = 0;
  #pragma omp parallel for reduction(+:aparicoes_23)
  for (size_t i = 0; i < MAX; i++) {
    int num;
    scanf("%d", &num);

    if(num == 23)
      aparicoes_23++;
  }

  printf("%d\n", aparicoes_23);
  return EXIT_SUCCESS;
}
