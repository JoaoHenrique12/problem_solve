
#include <stdio.h>
#include <omp.h>

int main() {
  int tid = 0, nthreads = 0;
  printf("\nRegião serial (thread única)\n\n");
  #pragma omp parallel
  {
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    printf("Região paralela (thread %d de %d threads)\n", tid, nthreads);
  } /* fim-pragma */
  printf("\nRegião serial (thread única)\n\n");
  #pragma omp parallel num_threads(4)
  {
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    printf("Região paralela (thread %d de %d threads)\n", tid, nthreads);
  } /* fim-pragma */
  printf("\nRegião serial (thread única)\n\n");
  return 0;
} /* fim-main */
/* Apenas a 3 esta correta */
/* 1. Se OMP_NUM_THREADS=6, na segunda região paralela desse código (linhas 13 a 18), serão geradas 10 threads e, portanto, 10 impressões (linha 17) */
/* 2. Se a linha 15 for movida para ficar fora da região paralela (entre as linhas 11 e 13), esse código passa a ser não compilável, pois não é possível saber o número de threads em uma região serial do código */
/* 3. Esse código é mais apropriado para funcionar em arquiteturas UMA (Uniform Memory Access) ou de memória compartilhada do que em arquiteturas NUMA (Non Uniform Memory Access) */
