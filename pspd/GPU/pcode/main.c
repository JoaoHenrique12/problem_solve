#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int i = 0;
    #pragma omp parallel
    {
        /* if (omp_get_thread_num() == 1) */
            i = i + 10;
    }
    printf("i = %d\n", i);
    return 0;
}

/* Nenhuma satisfaz */
/* I - A execução com o comando OMP_NUM_THREADS=4 t1 vai imprimir o valor 40 */
/* II - Se a linha 9 for suprimida, o binário equivalente acionado com o comando OMP_NUM_THREADS=3 t1 imprimirá sempre o valor 30 */
/* III - Se na linha 7 for acrescentada a declaração private(i) e houver supressão da linha 9, o binário equivalente acionado com o */
/* comando OMP_NUM_THREADS=6 t1, o programa vai imprimir 60 */
