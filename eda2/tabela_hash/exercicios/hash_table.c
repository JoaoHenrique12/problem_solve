#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  TRUE 0

#define mod 101

typedef struct
{
  char chave[22];
}Item;

void init_map(Item* mapa);
void insert_map(Item* mapa, Item item);
void remove_map(Item* mapa, Item item);
void printi(Item* mapa);

int hash(Item item);

Item null_item = {"\0"};

int main()
{
  Item tab[mod];
  Item aux;

  int n,n2;
  scanf("%d\n",&n);
  while(n--)
  {
    init_map(tab);
    scanf("%d\n",&n2);
    while(n2--)
    {
      scanf("%s\n",aux.chave);

      if( aux.chave[0] == 'A' )
      {
        strcpy(aux.chave , aux.chave + 4);
        insert_map(tab,aux);
      }
      else
      {
        strcpy(aux.chave , aux.chave + 4);
        remove_map(tab,aux);
      }
    }
    printi(tab);
  }

  return 0;
}
void remove_map(Item* mapa, Item item)
{
  int pos = hash(item);
  int reshi = pos;

  for(size_t i = 0; i < 20 ;i++)
  {
    pos = ( reshi + i *( 23 + i) ) % mod;
    if(strcmp(mapa[pos].chave,item.chave) == TRUE)
    {
      mapa[pos] = null_item;
      return;
    }
  }
}

void insert_map(Item* mapa, Item item)
{
  int pos = hash(item);
  int reshi = pos;
  int pi = -1 ;

  for(size_t i = 0; i < 20; i++)
  {
    pos = ( reshi + i *( 23 + i) ) % mod;

    if( !strlen(mapa[pos].chave) && pi == -1 )
      pi = pos;

    if(strcmp(mapa[pos].chave,item.chave) == TRUE)
      return;

  }

  if( pi != -1 )
    strcpy(mapa[pi].chave,item.chave);
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
    if( strlen(mapa[i].chave) )
      not_null++;

  printf("%d\n",not_null);
  for( int i = 0; i < mod ; i++)
    if( strlen( mapa[i].chave ) )
      printf("%d:%s\n",i,mapa[i].chave);
}
