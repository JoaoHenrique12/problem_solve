#include<stdio.h>

void insertion_sort( long* arrei, int size);
void printi( long* arrei, int size);
void swap( long* a, long* b ){ long aux = *a; *a = *b; *b = aux; }

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
	size_t i = 0;
	for(i; i < size - 1; i++)
		printf("%ld ",arrei[i]);

	printf("%ld\n",arrei[i]);
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
			swap(&arrei[j+1],&arrei[j]);
			j--;
		}
			

		arrei[j + 1] = key;
	}
}
