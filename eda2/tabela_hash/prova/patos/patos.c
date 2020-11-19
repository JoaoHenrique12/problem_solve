#include<stdio.h>
#include<stdlib.h>

#define mod 5010

int main()
{
  int n;
  long patos[mod];
  while( scanf("%d",&n), n != 0 )
  {
    long maior_repitido = -1,id_cor,cor;
    for( size_t i = 0; i < mod; i++)
      patos[i] = 0;

    for( size_t i = 0; i < n; i++)
    {
      scanf("%ld",&cor);

      patos[cor%mod]++;
      if( patos[cor%mod] > maior_repitido )
      {
        id_cor = cor;
        maior_repitido = patos[cor%mod];
      }
    }
    printf("%ld\n", id_cor );
  }
  return 0;
}
