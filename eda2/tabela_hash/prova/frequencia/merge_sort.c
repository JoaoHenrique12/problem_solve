#include<stdio.h>

void merge(long* arrei, int lo, int m, int hi);
void merge_sort( long* arrei, int lo, int hi);
void printi( long* arrei, int size);
void swap( long* a, long* b ){ long aux = *a; *a = *b; *b = aux; }

int main()
{
	long aux;
	long arrei[] = { 3 , 1 , 2 , 6 , 4 , 5 , 7 };
	int size = 7;

//	while( scanf("%ld",&aux) != EOF )
//		arrei[size++] = aux;

	merge_sort(arrei , 0 , size - 1);
	
	printi(arrei,size);

	return 0;
}
void printi( long* arrei, int size)
{
	size_t i = 0;
	for(i; i < size - 1; i++)
		printf("%ld ",arrei[i]);

	printf("%ld\n",arrei[i]);
}

void merge(long* arrei, int lo, int m, int hi)
{
  int i, j, k;
  int n1 = m - lo + 1;
  int n2 = hi - m;

  long L[n1], R[n2];

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

void merge_sort( long* arrei, int lo , int hi )
{
	if( lo < hi )
	{
    int m = lo + (hi - lo)/2;

    merge_sort(arrei,lo,m);
    merge_sort(arrei, m+1 ,hi);

    merge(arrei, lo, m, hi);
	}
}
