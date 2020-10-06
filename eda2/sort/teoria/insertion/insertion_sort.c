#include<stdio.h>

void insertion_sort( int* arrei,int l, int r);
void printi( int* arrei, int size);
void swap( int* a, int* b ){ int aux = *a; *a = *b; *b = aux; }
void cmpexch(int* a, int* b ){ if( *a > *b) swap(a,b);}

int arrei[50100];

int main()
{
	int aux;
	int size = 0;

	while( scanf("%d",&aux) != EOF )
		arrei[size++] = aux;

	insertion_sort(arrei,0,size-1);
	
	printi(arrei,size);

	return 0;
}
void printi( int* arrei, int size)
{
	size_t i = 0;
	for(i; i < size - 1; i++)
		printf("%d ",arrei[i]);

	printf("%d\n",arrei[i]);
}

void insertion_sort( int* arrei,int l, int r )
{
  for( int i = r; i > l; i-- )
    cmpexch( &arrei[i-1], &arrei[i]);

  for( int i = l + 2; i <= r; i++)
  {
    int j = i; int tmp = arrei[j];

    while( tmp < arrei[j - 1] )
      arrei[j--] = arrei[j - 1];

    arrei[j] = tmp;
  }
}
