#include<stdio.h>

int partition(int* arrei, int lo, int hi);
void quick_sort( int* arrei, int lo, int hi);
void printi( int* arrei, size_t size);

#define swap(a, b) do { int t; t = a; a = b; b = t; } while(0)

#define comp(a, b) do { if( a < b ) swap(a,b); } while(0)

int arrei[1000000000];
int main()
{
	size_t size = 0;
  scanf("%lu\n",&size);

  for(size_t i = 0; i < size; i++)
    scanf("%d",&arrei[i]);

//	while( scanf("%ld",&aux) != EOF )
//		arrei[size++] = aux;

	quick_sort(arrei , 0 , size - 1);
	
	printi(arrei,size);

	return 0;
}
void printi( int* arrei, size_t size)
{
	size_t i = 0;
	for(i; i < size - 1 ; i++)
		printf("%d ",arrei[i]);

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

void quick_sort( int* arrei, int lo , int hi )
{
	if( lo < hi )
	{
    int mei = (hi+lo)/2;
    comp( arrei[mei], arrei[hi] );
    comp( arrei[lo], arrei[mei] );
    comp( arrei[hi], arrei[mei] );

		int pi = partition( arrei, lo , hi );

		quick_sort( arrei, lo    , pi - 1 );
		quick_sort( arrei, pi + 1, hi     );
	}
}
