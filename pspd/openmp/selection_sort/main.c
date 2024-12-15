#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void selection_sort(int *v, int n){
	int i, j, min, tmp;

	for(i = 0; i < n - 1; i++){
		min = i;

    #pragma omp parallel for
		for(j = i + 1; j < n; j++)
			if(v[j] < v[min])
				min = j;

		tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;
	}
}

int main(int argc, char *argv[])
{
  int v[MAX];
  srand(10);
  for (size_t i = 0; i < MAX; i++) {
    v[i] = rand() % 100;
  }

  selection_sort(v, MAX);

  /* for (size_t i = 0; i < MAX; i++) { */
  /*   printf("%d ",v[i]); */
  /* } */
  /* printf("\n"); */

  return EXIT_SUCCESS;
}
