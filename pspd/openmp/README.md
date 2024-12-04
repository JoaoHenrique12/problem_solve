# OpenMP

```bash
gcc main.c -fopenmp

OMP_NUM_THREADS=10 ./a.out
```

```c
#include<omp.h>

#pragma omp parallel for
```

## Sincronizacao

Barreira: Cada thread espera na barreira até a chegada de todas as demais
#pragma omp barrier

Exclusão mútua: Define um bloco de código onde apenas uma thread pode executar por vez.
#pragma omp critical
#pragma omp atomic
