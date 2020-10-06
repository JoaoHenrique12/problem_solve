#include<stdio.h>
#include<stdlib.h>

#define VETORES_INTERCALAR 8
#define MAX_LEN_VECTOR 1e6 * 8

int vector_merged[(int)MAX_LEN_VECTOR];
int tmp_vector[(int)1e6+10];

int aux_vector[(int)1e6+10];

size_t len_vector_merged = 0;
size_t len_tmp_vector = 0;
size_t len_aux_vector = 0;


void merge()
{
  size_t i=0,j=0,k=0;
  for(i; i < len_vector_merged;i++)
    aux_vector[i] = vector_merged[i];

  len_aux_vector = i;
  i = 0;

  while( i < len_aux_vector && j < len_tmp_vector )
  {
    if( aux_vector[i] < tmp_vector[j] )
      vector_merged[k] = aux_vector[i++];
    else
      vector_merged[k] = tmp_vector[j++];
    k++;
  }

  while( i < len_aux_vector )
    vector_merged[k++] = aux_vector[i++];

  while( j < len_tmp_vector )
    vector_merged[k++] = tmp_vector[j++];

  len_vector_merged = k;
}

void printi()
{
  if(!len_vector_merged)
    return;
  size_t i = 0;
  for( i; i < len_vector_merged - 1; i++)
    printf("%d ",vector_merged[i]);

  printf("%d\n",vector_merged[i]);
}

int main()
{
  for( size_t l = 0; l < VETORES_INTERCALAR; l++)
  {
    scanf("%ld",&len_tmp_vector);

    for(size_t i = 0; i < len_tmp_vector; i++)
      scanf("%d",&tmp_vector[i]);

    merge();
  }
  printi();

  return 0;
}
