#include<stdio.h>

int main()
{
	long aux;
	long arrei[10010]	;
	int size = 0,id;

	while( scanf("%ld",&aux) != EOF )
		arrei[size++] = aux;
	// I.S.
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
	for(size_t i = 0; i < size; i++)
		if( i == ( size - 1 ) ) printf("%d\n",arrei[i]);
		else printf("%d ",arrei[i]);
	return 0;
}
