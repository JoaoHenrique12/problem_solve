#include<stdio.h>

void selection_sort( long* arrei, int size);
void printi( long* arrei, int size);

int main()
{
	long aux;
	long arrei[10010]	;
	int size = 0;

	while( scanf("%ld",&aux) != EOF )
		arrei[size++] = aux;

	selection_sort(arrei,size);
	
	printi(arrei,size);

	return 0;
}
void printi( long* arrei, int size)
{
	for(size_t i = 0; i < size; i++)
		if( i == ( size - 1 ) ) printf("%ld\n",arrei[i]);
		else printf("%d ",arrei[i]);
}

void selection_sort( long* arrei,int size )
{
	long aux;
	int id;
	for(size_t k = 0; k < size - 1; k++)
	{	
		long min = arrei[k];
		id = k;
		//find min
		for( size_t i = k + 1; i < size; i++ )
			if( arrei[i] < min ){	min = arrei[i]; id = i; }
		//swap
		aux = arrei[k]; arrei[k] = arrei[id];arrei[id] = aux;
	}
}
