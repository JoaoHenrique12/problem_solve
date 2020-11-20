#include<stdio.h>
#include<stdlib.h>

#include"arvore.h"

bool less(type_key n1,type_key n2)
{
  if( n1 < n2 )
    return true;
  else
    return false;
}

void cria_elemento(NO* el, type_key valor)
{
  el->esquerda = NULL;
  el->direita = NULL;
  el->chave = valor;
}

NO* insere(NO* raiz, NO* el)
{
  if( raiz == NULL ) return el;

  if( less(el->chave,raiz->chave) )
    raiz->esquerda = insere(raiz->esquerda,el);
  else
    raiz->direita = insere(raiz->direita,el);

  return raiz;
}

NO* contem(NO* raiz,type_key ch)
{
  if( raiz == NULL ) return NULL;
  if( raiz->chave == ch ) return raiz;
  
  if( less(raiz->chave,ch) )
    return( contem(raiz->direita,ch));
  else
    return( contem(raiz->esquerda,ch));
}

int caminhe(NO* raiz)
{
  if( !raiz )  return 0;
  return ( caminhe(raiz->esquerda) + caminhe(raiz->direita) + 1);
}
void imprime(NO* raiz)
{
  if( raiz == NULL ) return;
  printf("%d",raiz->chave);
  printf("(");
  imprime(raiz->esquerda);
  imprime(raiz->direita);
  printf(")");
}
