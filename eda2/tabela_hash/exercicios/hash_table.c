#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mod 101

typedef struct
{
  char chave[16];
}Item;

void init_map(Item* mapa);
void insert_map(Item* mapa, Item item);
void remove_map(Item* mapa, Item item);
void get_map(Item* mapa, Item* item);
void printi(Item* mapa);

int hash(Item item);

Item null_item = {"00\0"};

int main()
{
  Item tab[mod];
  Item aux;
  char op[4];

  init_map(tab);

  int n,n2;
  scanf("%d\n",&n);
  while(n--)
  {
    scanf("%d\n",&n2);
    while(n2--)
    {
      scanf("%[^:]:%s\n",op,aux.chave);
      if( op[0] == 'A' )
        insert_map(tab,aux);
      else
        remove_map(tab,aux);
    }
    printi(tab);
  }

  return 0;
}
void remove_map(Item* mapa, Item item)
{
  return;
}

void printi(Item* mapa)
{
  int not_null = 0;
  for( size_t i = 0; i < mod; i++)
    if( strcmp(mapa[i].chave,null_item.chave) != 0 )
      not_null++;

  printf("%d\n",not_null);

  for( size_t i = 0; i < mod && not_null; i++)
    if( strcmp(mapa[i].chave,null_item.chave) != 0 )
    {
      printf("hash:%d valor:%s\n",hash(mapa[i]),mapa[i].chave);
      not_null--;
    }
}

void insert_map(Item* mapa, Item item)
{
  int pos = hash(item);
  while( strcmp(mapa[pos].chave , null_item.chave) != 0 )
    pos = (pos+1) % mod;

  strcpy(mapa[pos].chave,item.chave);
}

void init_map(Item* mapa)
{
  for(size_t i = 0; i < mod; i++)
    mapa[i] = null_item;
}

int hash(Item item)
{
  int h = 0, fator = 19;
  for(size_t i = 0; item.chave[i] != '\0'; i++)
    h = item.chave[i] * (i+1);

  h = (h*fator) % mod;

  return h;
}
