#include<stdio.h>
#include<stdlib.h>

__global__ void cuda_hello() {
  printf("Na GPU!\n");
}

int main(int argc, char *argv[])
{
  printf("Na CPU!\n");
  cuda_hello<<<1,1>>>();
  cudaDeviceSynchronize();
  return EXIT_SUCCESS;
}
