#include<stdio.h>
#include<stdlib.h>

#include"arvore.h"


int main()
{
  NO* raiz = malloc(sizeof(NO));
  cria_elemento(raiz,22);

  NO* n1 = malloc(sizeof(NO));
  NO* n2 = malloc(sizeof(NO));
  cria_elemento(n1,15);
  cria_elemento(n2,25);

  insere(raiz,n1);
  insere(raiz,n2);
  int nEl = caminhe(raiz);
  printf("%d\n",nEl);

  imprime(raiz);
  printf("\n");

  return 0;
}
