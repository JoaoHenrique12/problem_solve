#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#define MAX 1000

int main()
{
  char texto_base[] = "abcdefghijklmnopqrstuvwxyz 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  int* indice = (int*) malloc(sizeof(int));
  *indice = 0;
  struct timeval tv;

  int number, tmp_index, i, cont=0;
  while (cont < MAX) {
    gettimeofday(&tv, NULL);
    number = ((tv.tv_usec/47) % 3) + 1;
    tmp_index = *indice;
    for(i = 0; i < number; i++)
      if(!(tmp_index + i > sizeof(texto_base)))
        fprintf(stderr, "%c", texto_base[tmp_index + i]);
    *indice = tmp_index + i;

    if(tmp_index + i > sizeof(texto_base)){
      fprintf(stderr,"\n");
      *indice = 0;
    }
    cont++;
  }

  printf("\n");

  return EXIT_SUCCESS;
}