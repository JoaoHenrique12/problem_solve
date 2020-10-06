#include<stdio.h>
#include<stdlib.h>

int partition(int* arrei, int lo, int hi);
void quick_select( int* arrei, int lo, int hi,int k);
void printi( int* arrei, size_t l,size_t r);


void merge_sort( int* arrei, int lo, int hi);
void merge(int* arrei, int lo, int m, int hi);

#define swap(a, b) do { int t; t = a; a = b; b = t; } while(0)

#define comp(a, b) do { if( a < b ) swap(a,b); } while(0)

int arrei[ 33554432 + 10 ];
//33554432, lim elem estabelecidos no problema
int main()
{
  int aux;
	size_t size = 0;

  int n,p,x;
  scanf("%d %d %d\n",&n,&p,&x);

	while( scanf("%d\n",&aux),size != n )
		arrei[size++] = aux;

  //printf("Size %lu\n",size);
  size_t l = x * p;
  size_t r = (x * p + x - 1);

  if( r >= size ) r = size - 1;

 // printf("L - %lu\nR - %lu\n",l,r);

	quick_select(arrei , 0 ,size - 1,l);
	quick_select(arrei , l ,size - 1,r);

  merge_sort(arrei,l,r);
	
	printi(arrei,l,r + 1);


	return 0;
}

void printi( int* arrei, size_t l,size_t r)
{
	size_t i = l;
	for(i; i < r - 1 ; i++)
		printf("%d\n",arrei[i]);

	printf("%d\n",arrei[i]);
}

int partition(int* arrei, int lo, int hi)
{
	int pivot = arrei[hi];
	int i = lo; 

	for( int j = lo; j < hi; j++ )
	{
		if( arrei[j] < pivot )
		{
			swap( arrei[i] , arrei[j] );
			i++;
		}
	}
	swap( arrei[i] , arrei[hi] );

	return i;
}

void quick_select( int* arrei, int lo , int hi, int k )
{
	if( lo < hi )
	{
    int mei = (hi+lo)/2;
    comp( arrei[mei], arrei[hi] );
    comp( arrei[lo], arrei[mei] );
    comp( arrei[hi], arrei[mei] );

		int pi = partition( arrei, lo , hi );

		if(pi > k)  quick_select( arrei, lo    , pi - 1 , k);
    else if(pi < k)quick_select( arrei, pi + 1, hi  , k);
	}
}

void merge(int* arrei, int lo, int m, int hi)
{
  int i, j, k;
  int n1 = m - lo + 1;
  int n2 = hi - m;

  int L[n1], R[n2];

  for ( i = 0; i < n1; i++ )
    L[i] = arrei[ lo + i ];

  for ( j = 0; j < n2; j++ )
    R[j] = arrei[ m + 1 + j ];

  i = 0; j = 0; k = lo;

  while( i < n1 && j < n2 )
  {
    if( L[i] <= R[j])
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

void merge_sort( int* arrei, int lo , int hi )
{
	if( lo < hi )
	{
    int m = lo + (hi - lo)/2;

    merge_sort(arrei,lo,m);
    merge_sort(arrei, m+1 ,hi);

    merge(arrei, lo, m, hi);
	}
}
