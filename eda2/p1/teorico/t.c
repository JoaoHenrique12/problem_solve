#include<stdio.h>

void printi( int* arrei, size_t l,size_t r);

int sep( int v[], int p, int r) 
{
  int q, i, j, t;
  i = p; q = (p + r) / 2; j = r;
  do 
  {
    while (v[i] < v[q]) ++i;
    while (v[j] > v[q]) --j;
    if (i <= j) 
    {
      if (v[i] < v[j]) 
        t = v[i], v[i] = v[j], v[j] = t;
      ++i, --j;
    }
  } while (i <= j);
  return i - 1;
}

int main()
{
  //int v[] = {3, 2, 7, 4, 9, 1, 5};
  int v[] = {3, 3, 3, 4, 9, 1, 5};
  int s = sep(v,0,7);

  printf("p1\n");
  printi(v,0,s+1);

  printf("\np2\n");
  printi(v,s + 1,7);
  printf("\n");

  return 0;
}

void printi( int* arrei, size_t l,size_t r)
{
	size_t i = l;
	for(i; i < r  ; i++)
		printf("%d ",arrei[i]);
}
