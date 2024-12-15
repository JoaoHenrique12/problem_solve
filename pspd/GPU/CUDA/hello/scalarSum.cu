#include<stdio.h>
#include<stdlib.h>

__global__ void add(int a, int b, int* c) {
  *c = a + b;
}

int main(int argc, char *argv[])
{
  int a = 10, b = 30, c = -1;
  int *dev_c;
  
  // Allocate memory on the GPU
  cudaMalloc((void**)&dev_c, sizeof(int));
  
  // Launch the kernel
  add<<<1,1>>>(a, b, dev_c);
  
  // Wait for kernel to finish
  cudaDeviceSynchronize();
  
  // Copy result back to host
  cudaMemcpy(&c, dev_c, sizeof(int), cudaMemcpyDeviceToHost);
  
  printf("%d + %d = %d\n", a, b, c);

  // Free GPU memory
  cudaFree(dev_c);
  
  return EXIT_SUCCESS;
}
