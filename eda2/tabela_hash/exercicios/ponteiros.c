#include<stdio.h>
#include<stdlib.h>

#define mod  2500000
#define limit_index 40

typedef struct{
  unsigned long long chave;
  unsigned long long next;
  unsigned long long before;

} Item;

int hash(Item item)
{
  return item.chave ;
}

void init(Item* table);
void insere(Item* table, Item item);
void retira(Item* table,Item* rmd,int* ind, Item item);
void printi(Item* arrei,long tipo, Item init,Item* rmd,int ind);

Item null_item = { 0, 0 , 0 };

short equal(Item i1, Item i2)
{
  return (i1.chave == i2.chave && i1.next == i2.next && i1.before == i2.before );
}

int main()
{
  int n;
  int ind = 0;
  Item aux;
  Item* table = malloc(sizeof(Item) * mod);
  Item* rmd = malloc(sizeof(Item) * mod);

  Item pt1;
  Item pt2;

  init(table);
  scanf("%llx %llx %llx\n",&pt1.chave,&pt1.before,&pt1.next);
  scanf("%llx %llx %llx\n",&pt2.chave,&pt2.before,&pt2.next);

  insere(table,pt1);
  insere(table,pt2);

  while(scanf("%llx %llx %llx\n",&aux.chave,&aux.before,&aux.next) != EOF)
    insere(table,aux);

  Item head ;
  head = table[pt1.before];
  Item navegador = pt1;
  while(navegador.chave != pt2.chave)
  {
    aux = table[navegador.next];
    retira(table,rmd,&ind,navegador);
    navegador = aux;
  }
  retira(table,rmd,&ind,pt2);

  printi(table,0,head, rmd, ind);
  printi(rmd,ind,aux, rmd, ind);

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

void retira(Item* table,Item* rmd,int* ind, Item item)
{
  int pos = hash(item);
  while(!equal(table[pos], item))
    pos = (pos+1)%mod;

  table[table[pos].before].next = table[pos].next;

  rmd[*ind] = item;
  *ind = *ind + 1;
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

void printi(Item* arrei,long tipo,Item init,Item* rmd,int ind)
{
  if( tipo != 0)
    for( size_t i = 0; i < tipo; i++)
      printf("%llx\n",arrei[i].chave);
  else
  {
    Item navegador = init;
    while( !equal(arrei[navegador.before],null_item) || arrei[navegador.before].chave != 0 )
      navegador = arrei[navegador.before];

    for( navegador; !equal( navegador,null_item); navegador = arrei[navegador.next])
      printf("%llx %llx %llx\n",arrei[navegador.chave].chave,arrei[navegador.chave].before,arrei[navegador.chave].next );

    printf("%llx %llx %llx\n",arrei[rmd[0].before].chave,arrei[rmd[0].before].before,arrei[rmd[ind-1].next].chave);

    printf("\n");
  }
}
