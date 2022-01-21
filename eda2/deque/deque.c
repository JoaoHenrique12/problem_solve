#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
  int value;
  struct no* next;
  struct no* back;
}NO;

typedef struct lista{
  NO* begin;
  NO* end;
  int size;
}LISTA;

void init_lista(LISTA* l)
{
  l->begin = NULL;
  l->end = NULL;
  l->size = 0;
}

void cria_no(NO* node, int value)
{
  node->value = value;
  node->next = NULL;
  node->back = NULL;
}

void insere_lista_fim(LISTA* l, NO* element)
{
  if(l->begin == NULL)
  {
    l->begin = element;
    l->end = element;
  }else
  {
    NO* aux;
    aux = l->end;

    element->back = aux;
    aux->next = element;
    l->end = element;

    l->end->next = l->begin;
    l->begin->back = l->end;
  }
  l->size++;
}

void printa(LISTA* l )
{
  NO* it;
  it = l->begin;
  while(it)
  {
    printf("%c\n",it->value);
    it = it->next;
  }
}

void executa(LISTA* l,int qt,int salto,int sentido)
{
  printf("Saida: ");
  NO* it = l->begin;
  while( l->size != 1 )
  {
    for(int i = 0; i < (salto - 1) ;i++)
    {
      if( sentido == 1)
        it = it->next;
      else
        it = it->back;
    }
    printf("%c ",it->value);

    NO* aux = it->back;
    aux->next = it->next;
    //printf("%c",aux->value);

    aux = it->next;
    aux->back = it->back;

    //printf("%c",aux->value);

    free(it);
    it = aux;
    l->size--;
  }
  printf("\nSoldado sortudo:%c\n",it->value);

}
