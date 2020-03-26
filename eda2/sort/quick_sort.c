#include<stdio.h>

int partition(long* arrei, int lo, int hi);
void quick_sort( long* arrei, int lo, int hi);
void printi( long* arrei, int size);
void swap( long* a, long* b ){ long aux = *a; *a = *b; *b = aux; }

int main()
{
	long aux;
	long arrei[] = { 3 , 1 , 2 , 6 , 4 , 5 , 7 };
	int size = 7;

//	while( scanf("%ld",&aux) != EOF )
//		arrei[size++] = aux;

	quick_sort(arrei , 0 , size - 1);
	
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
int partition(long* arrei, int lo, int hi)
{
	long pivot = arrei[hi];
	int i = lo - 1; 

	for( int j = lo; j < hi; j++ )
	{
		if( arrei[j] < pivot )
		{
			i++;
			swap( &arrei[i] , &arrei[j] );
		}
	}
	swap( &arrei[i + 1] , &arrei[hi] );

	return ( i + 1 );
}

void quick_sort( long* arrei, int lo , int hi )
{
	if( lo < hi )
	{
		int pi = partition( arrei, lo , hi );

		quick_sort( arrei, lo, pi - 1);
		quick_sort( arrei, pi + 1, hi);
	}
}
