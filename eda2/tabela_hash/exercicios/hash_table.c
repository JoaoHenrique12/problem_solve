#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  TRUE 0

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
short colision(Item* mapa, int reshi);

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
  int pos = hash(item);
  int reshi = pos;

  size_t i = 1;
  for(i; i < 20 && !colision(mapa,pos); i++)
  {
    pos =( reshi + i * i + 23 * i) % mod;
  }

  if( i < 20 && strcmp(mapa[pos].chave , item.chave ) == TRUE )
      strcpy(mapa[pos].chave,null_item.chave);
}


void insert_map(Item* mapa, Item item)
{
  int pos = hash(item);
  int reshi = pos;

  size_t i = 1;
  for(i; i < 20 && colision(mapa,pos) ; i++)
  {
    if(strcmp(mapa[pos].chave,item.chave) == TRUE)
      return;
    pos = ( reshi + i * i + 23 * i) % mod;
  }

  if( i < 20 )
    strcpy(mapa[pos].chave,item.chave);
}
short colision(Item* mapa, int reshi)
{
  short deu_merda = 1;
  if( strcmp(mapa[reshi].chave,null_item.chave) == TRUE )
    deu_merda = 0;
  return deu_merda;
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
    h += item.chave[i] * (i+1);

  h = (h*fator) % mod;

  return h;
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
      printf("%ld:%s\n",i,mapa[i].chave);
      not_null--;
    }
}
