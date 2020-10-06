# T1

A estabilidade de um algoritmo se refere ao fato de que seja mantida a ordem relativa dos elementos de chaves similare.



seja a lista:

A B               X Y C
1 1 3 2 6 5 4 8 9 7 7 1

passo 1 ( Bubble sort ):

A B C               X Y 
1 1 1 3 2 6 5 4 8 9 7 7 

... ( ordenando os elementos ate o 7, que e o caso interessante )

A B C               X Y 
1 1 1 2 3 4 5 6 8 9 7 7 
                    |  ponteiro parado no 7 marcado com X.

A B C                 Y 
1 1 1 2 3 4 5 6 8 9 9 7  - Segura na mao o 7 com X
                      Y
1 1 1 2 3 4 5 6 8 8 9 7  - Segura na mao o 7 com X
                X     Y
1 1 1 2 3 4 5 6 7 8 9 7  
                      | ponteiro no 7 com Y

A B C           X      
1 1 1 2 3 4 5 6 7 8 9 9  - Segura na mao o 7 com Y
                X
1 1 1 2 3 4 5 6 7 8 8 9  - Segura na mao o 7 com Y
                X Y
1 1 1 2 3 4 5 6 7 7 8 9  

Nota: Insertion Sort e um algoritmo de ordenacao estavel
Miha implementacao de IS.
```
void insertion\_sort( int\* arrei,int l, int r )
{
  for( int i = r; i > l; i-- )
    cmpexch( &arrei[i-1], &arrei[i]);

  for( int i = l + 2; i <= r; i++)
  {
    int j = i; int tmp = arrei[j];

    while( tmp < arrei[j - 1] )
      arrei[j--] = arrei[j - 1];

    arrei[j] = tmp;
  }
}
```

# T2

Se colocar i - 1 so vai mudar a posicao do pivo escolhido, se ele fica no array de cima ou de baixo

Exemplo de onde a funcao nao age como o esperado:

int v[] = {3, 3, 3, 4, 9, 1, 5};

O problema e que a funcao no atual momento sempre faz a troca dentro do while, sem verificar se v[i] realmente e menor que v[j].

```
int sep( int v[], int p, int r) 
{
  int q, i, j, t;
  i = p; q = (p + r) / 2; j = r;
  do 
  {
    while (v[i] < v[q]) ++i;
    while (v[j] > v[q]) --j;
    if (i <= j) 
    {
      if (v[i] < v[j]) 
        t = v[i], v[i] = v[j], v[j] = t;
      ++i, --j;
    }
  } while (i <= j);
  return i - 1;
}
```
