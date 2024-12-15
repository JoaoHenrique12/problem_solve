#include <stdio.h>
#include<stdlib.h>
#include <omp.h>

double cascade_sum(double *arr, int n) {
    #pragma omp parallel
    {
        for (size_t shift = 1; shift < n; shift*=2) {
            #pragma omp for
            for (size_t i = 0; i < n; i = 2 * shift + i) {
                arr[i] += arr[i + shift];
            }
        }
    }

    return arr[0];
}

int main() {
    const int n = (int) 1024 * 1024;
    double *arr = (double*)malloc(n * sizeof(double));

    // Initialize the array with some values
    for (int i = 0; i < n; ++i) {
        arr[i] = 1.0;
    }

    double start_time = omp_get_wtime();
    double result = cascade_sum(arr, n);
    /* double result = 0.0; */
    /* for(int i = 0; i < n; i++) result += arr[i]; */
    double end_time = omp_get_wtime();

    printf("Sum: %f\n", result);
    printf("Time taken: %f seconds\n", end_time - start_time);

    free(arr);
    return 0;
}
