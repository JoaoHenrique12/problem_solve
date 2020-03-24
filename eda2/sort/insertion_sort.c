#include<stdio.h>

void insertion_sort( long* arrei, int size);
void printi( long* arrei, int size);

int main()
{
	long aux;
	long arrei[10100];
	int size = 0;

	while( scanf("%ld",&aux) != EOF )
		arrei[size++] = aux;

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
	long key,j,aux;
	for(size_t i = 1; i < size ; i++)
	{
		key = arrei[i];
		j = i - 1;

		while( j >=0 && arrei[j] > key )
		{
			aux = arrei[j];
			arrei[j + 1] = arrei[j];
			arrei[j--] = aux;
		}
		arrei[j + 1] = key;
	}
}
