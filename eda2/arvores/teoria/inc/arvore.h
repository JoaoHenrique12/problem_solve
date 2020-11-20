#ifndef ARVORE_H
#define ARVORE_H

#define true 1
#define false 0

typedef char bool;
typedef int type_key;

typedef struct no
{
  type_key chave;
  struct no* direita;
  struct no* esquerda;
}NO;

bool less(type_key n1,type_key n2);
void cria_elemento(NO* el,type_key valor);

NO* insere(NO* raiz,NO* el);
NO* contem(NO* raiz,type_key ch);
int caminhe(NO* raiz);

void imprime(NO* raiz);

#endif
