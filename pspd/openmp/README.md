# OpenMP

```bash
gcc main.c -fopenmp

OMP_NUM_THREADS=10 ./a.out
```

```c
#include<omp.h>

omp_get_num_threads()
omp_get_max_threads()
omp_get_thread_num()

#pragma omp parallel

#pragma omp section
#pragma omp parallel section

#pragma omp parallel for
#pragma omp parallel for shared(vetor, n)
#pragma omp parallel for private(vetor, n)

#pragma omp parallel for reduction(+:aparicoes_23)
```

## Sincronizacao

Barreira: Cada thread espera na barreira até a chegada de todas as demais
#pragma omp barrier

Exclusão mútua: Define um bloco de código onde apenas uma thread pode executar por vez.
#pragma omp critical
#pragma omp atomic
