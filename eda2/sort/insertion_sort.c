#include<stdio.h>

void insertion_sort( long* arrei, int size);
void printi( long* arrei, int size);

int main()
{
	long aux;
	long arrei[] = {3 , 1 , 2 , 4 , 6 , 5 , 7};
	int size = 7;
/*
	while( scanf("%ld",&aux) != EOF )
		arrei[size++] = aux;
*/
	insertion_sort(arrei,size);
	
	printi(arrei,size);

	return 0;
}
void printi( long* arrei, int size)
{
	for(size_t i = 0; i < size; i++)
		if( i == ( size - 1 ) ) printf("%ld\n",arrei[i]);
		else printf("%d ",arrei[i]);
}

void insertion_sort( long* arrei,int size )
{
	long key;
	int id;
	for(size_t i = 1; i < size ; i++)
	{
		key = arrei[i];
		id = i;
		for( int j = i - 1; j >= 0 && id; j-- )
		{
			if( key < arrei[j] )
			{
				long aux = arrei[id];
				arrei[id--] = arrei[j];
				arrei[j] = aux;
			}
			else
			{
				arrei[id--] = key;
				break;
			}
		}
	}
}
