#include<stdio.h>
#include "cadeira_futurista.hpp"

CadeiraFuturista::CadeiraFuturista():Cadeira()
{
  this->n_pernas = 0;
}

void CadeiraFuturista::apresentar()
{
  printf("\n\tCadeira super futurista ->~~~~\n");
  Cadeira::apresentar();
}
