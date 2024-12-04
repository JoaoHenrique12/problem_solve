# OpenMP

```bash
gcc main.c -fopenmp

OMP_NUM_THREADS=10 ./a.out
```

```c
#include<omp.h>

#pragma omp parallel for
```
