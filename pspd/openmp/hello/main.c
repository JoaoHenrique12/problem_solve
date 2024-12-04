#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define MAX 1000

int main(int argc, char *argv[])
{
  int tid = -1, n = 0; 
  #pragma omp parallel
  {
    n = omp_get_num_threads();
    tid = omp_get_thread_num();
    printf("threads, tid: %d, %d\n", n, tid);
  }
  return EXIT_SUCCESS;
}
