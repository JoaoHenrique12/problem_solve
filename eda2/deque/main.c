#include<stdio.h>
#include<stdlib.h>
#include "deque.c"

// flavius josephus problem

int main()
{
  LISTA* roda = malloc( sizeof( LISTA ) );
  init_lista(roda);

  int quantia_soldados;
  printf("Quantia de soldados:");
  scanf("%d",&quantia_soldados);

  int salto;
  printf("Salto:");
  scanf("%d",&salto);

  int sentido;
  printf("1 - > sentido Horario\n");
  printf("2 - > sentido Anti-horario\n");
  printf("Sentido:");
  scanf("%d",&sentido);


  for(int i = 0; i < quantia_soldados; i++)
  {
    NO* aux = malloc( sizeof( NO ) );
    cria_no(aux,i+65);
    insere_lista_fim(roda,aux);
  }

  executa(roda,quantia_soldados,salto,sentido);
  //printa(roda);

  return 0;
}
