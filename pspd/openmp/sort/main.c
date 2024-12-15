#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX 1000

void comparaTroca(int* a, int* b)
{
  int tmp;
  if(*a > *b)
    { tmp = *a; *a = *b; *b = tmp; }
}

void ParImpar(int a[], int n)
{
  int i, j, nHalf, ultPar, ultImpar;

  nHalf = n/2; ultPar = nHalf - 1;

  if (n % 2 == 0)
    ultImpar = nHalf - 2;
  else
    ultImpar = nHalf - 1;

  #pragma omp parallel
  {
    for(int i = 0; i < n-1; i++)
    {
      #pragma omp for
      for (j = 0; j <= ultImpar; j++) {
        comparaTroca(&a[2*j + 1], &a[2*j + 2]);
      }
      #pragma omp for
      for (j = 0; j <= ultPar; j++) {
        comparaTroca(&a[2*j], &a[2*j + 1]);
      }
    }
  }
}

int main() {
  int arr[MAX];
  srand(10);
  for (size_t i = 0; i < MAX; i++) {
    arr[i] = rand() % 100;
  }


  ParImpar(arr, MAX);

  for (int i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
