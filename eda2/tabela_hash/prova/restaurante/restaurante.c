#include<stdlib.h>
#include<stdio.h>

int main()
{
  int ind, rest;
  for(ind = 1; scanf("%d",&rest) != EOF ; ind++)
  {
    printf("Dia %d\n",ind);
    int maior_nt = -1, current_nt;
    long maior_id = -1, current_id;
    for( size_t i = 0; i < rest; i++)
    {
      scanf("%ld %d",&current_id,&current_nt);
      if( current_nt > maior_nt )
      {
        maior_nt = current_nt;
        maior_id = current_id;
      }
      else if( current_nt == maior_nt && current_id < maior_id)
        maior_id = current_id;
    }
    printf("%ld\n\n",maior_id);
  }

  return 0;
}
