#include <stdio.h>
#include "cadeira_classica.hpp"

CadeiraClassica::CadeiraClassica():Cadeira()
{
  this->set_preco(1000);
}


// Se uma cadeira clássica for barata então ela não é clássica, mas sim velha.
void CadeiraClassica::set_preco(int preco)
{
  if( preco < 1000 )
  {
    preco += 1000;
    printf("\nCadeira barata, aumento automático de preço para %d\n",preco);
  }
  this->preco = preco; 
}

void CadeiraClassica::apresentar()
{
  printf("\n\tClassical chair presents:\n");
  Cadeira::apresentar();
  printf("Peço: R$ %d\n", this->preco);
}
