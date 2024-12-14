#include <stdio.h>
#include <omp.h>
int main(void) {
  int myid, nthreads;
  #pragma omp parallel private(myid) private(nthreads)
  {
    myid = omp_get_thread_num();
    #pragma omp single
    nthreads = omp_get_num_threads();
    printf("%d de %d - Hello, World!\n", myid, nthreads);
  }
  return 0;
} /* fim-main */
