#include <stdio.h>
#include <omp.h>
#define MAX 100

int main(int argc, char *argv[]) {
    #pragma omp parallel
    {
        int soma = 0;
        #pragma omp for
        for (int i = 0; i < MAX; i++) {
            soma += omp_get_num_threads() * i;
        } /* fim-for */
        printf("Thread[%d] iterou %d vezes\n", 
               omp_get_thread_num(), soma);
    } /* fim omp parallel */
    return 0;
}

// TODAS ERRADAS
//(F) A execução com o comando OMP_NUM_THREADS=4 t1 vai imprimir que cada thread foi executada 25 vezes
//(F) Se este programa for acionado tendo a variável OMP_NUM_THREADS um valor maior do que o número de núcleos da máquina, apenas as threads equivalentes ao número de núcleos serão criadas
//(F) Se o programa for executado numa máquina com 10 núcleos de processamento e a variável OMP_NUM_THREADS estiver com valor igual a 20, o programa não será ativado
