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

Item null_item = {"\0"};

int main()
{
  Item tab[mod];
  Item aux;
  char op[4];


  int n,n2;
  scanf("%d\n",&n);
  while(n--)
  {
    init_map(tab);
    scanf("%d\n",&n2);
    while(n2--)
    {
      aux.chave[0] = '\0';
      scanf("%[^:]:%s\n",op,aux.chave);

      if( aux.chave[0] == '\0')
        continue;

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

  for(size_t i = 0; i < 20 ;i++)
  {
    if(strcmp(mapa[pos].chave,item.chave) == TRUE)
    {
      strcpy(mapa[pos].chave,null_item.chave);
      return;
    }
    pos = ( reshi + i * i + 23 * i) % mod;
  }
}

void insert_map(Item* mapa, Item item)
{
  int pos = hash(item);
  int reshi = pos;
  int pi = -1 ;

  for(size_t i = 0; i < 20; i++)
  {
    if( !colision(mapa,pos) && pi == -1 )
      pi = pos;

    if(strcmp(mapa[pos].chave,item.chave) == TRUE)
      return;

    pos = ( reshi + i * i + 23 * i) % mod;
  }

  if( pi != -1 )
    strcpy(mapa[pi].chave,item.chave);
}
short colision(Item* mapa, int reshi)
{
  short deu_merda = 1;
  if( mapa[reshi].chave[0] == null_item.chave[0] )
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

  for( int i = 0; i < mod && not_null; i++)
    if( mapa[i].chave[0] != null_item.chave[0] )
    {
      printf("%d:%s\n",i,mapa[i].chave);
      not_null--;
    }
}
