#include<stdio.h>
#include<stdlib.h>

__global__ void add(int N, float* a, float* b, float* c) {
  int tid = threadIdx.x;
  if (tid < N)
    c[tid] = a [tid] + b[tid];
}

int main(int argc, char *argv[])
{
  float *a, *b, *c;
  int N = 1000;
  a = (float*) malloc(N*sizeof(float));
  b = (float*) malloc(N*sizeof(float));
  c = (float*) malloc(N*sizeof(float));

  for (int i = 0; i < N; i++)
    { a[i] = -i; b[i] = i * i; }

  float *dev_a, *dev_b, *dev_c;
  cudaMalloc((void**)&dev_a, N*sizeof(float));
  cudaMalloc((void**)&dev_b, N*sizeof(float));
  cudaMalloc((void**)&dev_c, N*sizeof(float));

  cudaMemcpy(dev_a, a, N*sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_b, b, N*sizeof(float), cudaMemcpyHostToDevice);
  add<<<1,N>>>(N, dev_a, dev_b, dev_c);
  cudaMemcpy(dev_c, c, N*sizeof(float), cudaMemcpyDeviceToHost);

  free(a); free(b); free(c);
  cudaFree(dev_a); cudaFree(dev_b); cudaFree(dev_c);
  return 0;
}
