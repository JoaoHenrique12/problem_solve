#include<stdio.h>
#include<stdlib.h>

#define MAX 1024
#define MAX2 256

typedef struct
{
  char ind;
  int fr;
}Item;

void merge(Item* arrei, int lo, int m, int hi);
void merge_sort( Item* arrei, int lo, int hi);
void swap( Item* a, Item* b ){ Item aux = *a; *a = *b; *b = aux; }

int main()
{
  char st;
  int map[MAX2];

  Item ordenado[MAX2];
  while(1)
  {
    if( scanf("%c",&st) == EOF )
      break;

    for(size_t i = 0 ; i < MAX2; i++)
      map[i] = 0;

    map[st]++;
    while(scanf("%c",&st), st != '\n' )
      map[st]++;

    int j = 0;
    for(size_t i = 0 ; i < MAX2; i++)
    {
      if( map[i] == 0 )
        continue;
      ordenado[j].ind = i;
      ordenado[j].fr = map[i];
      j++;
    }
    merge_sort(ordenado, 0 ,j - 1);

    for(size_t i = 0 ; i < j; i++)
      printf("%d %d\n",ordenado[i].ind,ordenado[i].fr);
    printf("\n");
  }
  return 0;
}
void merge(Item* arrei, int lo, int m, int hi)
{
  int i, j, k;
  int n1 = m - lo + 1;
  int n2 = hi - m;

  Item L[n1], R[n2];

  for ( i = 0; i < n1; i++ )
    L[i] = arrei[ lo + i ];

  for ( j = 0; j < n2; j++ )
    R[j] = arrei[ m + 1 + j ];

  i = 0; j = 0; k = lo;

  while( i < n1 && j < n2 )
  {
    if( L[i].fr < R[j].fr)
      arrei[k] = L[i++];
    else if( L[i].fr == R[j].fr && L[i].ind < R[j].ind )
      arrei[k] = L[i++];
    else
      arrei[k] = R[j++];

    k++;
  }
  while( i < n1)
    arrei[k++] = L[i++];
  while( j < n2)
    arrei[k++] = R[j++];
}

void merge_sort( Item* arrei, int lo , int hi )
{
	if( lo < hi )
	{
    int m = lo + (hi - lo)/2;

    merge_sort(arrei,lo,m);
    merge_sort(arrei, m+1 ,hi);

    merge(arrei, lo, m, hi);
	}
}
