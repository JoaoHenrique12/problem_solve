#ifndef DEQUE_H
#define DEQUE_H

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

void init_lista(LISTA* l);
void cria_no(NO* node, int value);
void insere_lista_fim(LISTA* l, NO* element);
void executa(LISTA* l,int qt,int salto,int sentido);

#endif // !DEQUE_H
