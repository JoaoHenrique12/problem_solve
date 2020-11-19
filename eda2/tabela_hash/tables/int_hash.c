#include<stdio.h>
#include<stdlib.h>

#define mod 280000
#define limit_index 40

typedef struct{
  int chave;
} Item;

int hash(Item item)
{
  int a = 31415, b = 27183;
  return (((item.chave * a * b ) % mod + mod ) % mod);
}

void init(Item* table);
void insere(Item* table, Item item);
void retira(Item* table, Item item);
short is_in(Item* table, Item item);

Item null_item = { -1 };

short equal(Item i1, Item i2)
{
  return (i1.chave == i2.chave);
}

int main()
{
  int n;
  Item aux;
  Item table[mod];

  init(table);
  scanf("%d\n",&n);

  for(size_t i = 0 ;i < n;i++)
  {
    scanf("%d ",&aux.chave);
    insere(table,aux);
  }

  while( scanf("%d",&aux.chave) != EOF )
  {
    short presente = is_in(table,aux);
    if( presente )
      printf("sim\n");
    else
      printf("nao\n");
  }

  return 0;
}
short is_in(Item* table, Item item)
{
  short present = 0;
  int pos = hash(item);
  for(size_t i = pos; i < pos + limit_index; i++ )
    if(equal(table[i%mod],item)) 
    {
      present = 1;
      break;
    }
  return present;
}

void retira(Item* table, Item item)
{
  int pos = hash(item);
  while(!equal(table[pos], item))
    pos = (pos+1)%mod;

  table[pos] = null_item;
}
void insere(Item* table, Item item)
{
  int pos = hash(item);
  while(!equal(table[pos], null_item))
    pos = (pos+1)%mod;

  table[pos] = item;
}

void init(Item* table)
{
  for(size_t i = 0; i < mod ; i++)
      table[i] = null_item;
}
