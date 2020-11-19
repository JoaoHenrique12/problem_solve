#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mod 101

typedef struct
{
  int chave;
}Item;

typedef struct
{
  Item item;
  Item* next;
}Node;

void init_map(Node* mapa);
void insert_map(Node* mapa, Item item);
void remove_map(Node* mapa, Item item);
void printi(Node* mapa);

int hash(Item item);

Item null_item = {-1};
Node null_node = { -1 , NULL};

short equal(Item n1, Item n2)
{
  return ( n1.chave == n2.chave );
}

int main()
{
  Node tab[mod];
  Item aux;

  int n;
  scanf("%d\n",&n);
  init_map(tab);
  for(size_t i = 0 ; i < n; i++)
  {
    scanf("%d\n",&aux.chave);
    insert_map(tab,aux);
  }

  return 0;
}
void insert_map(Node* mapa, Item item)
{
  Node* new_node = (Node*) malloc(sizeof (Node));
  new_node->next = NULL;
  new_node->item = item;

  int pos = hash(item);

  Node* navegador = (Node*) malloc(sizeof (Node));
  navegador->next = mapa[pos].next; 

  while( navegador->next != NULL )
    navegador->next =  navegador->next;

  navegador->next = new_node;
}

void init_map(Node* mapa)
{
  for(size_t i = 0; i < mod; i++)
    mapa[i] = null_node;
}

int hash(Item item)
{
  int h = 0, fator = 19, fator2 = 123;

  h = ((h*fator * fator2) % mod + mod ) % mod;

  return h;
}
void printi(Node* mapa)
{
  for( int i = 0; i < mod ; i++)
    if( !equal( mapa[i].item, null_item ) )
      printf("%d:%d\n",i,mapa[i].item.chave);
}
