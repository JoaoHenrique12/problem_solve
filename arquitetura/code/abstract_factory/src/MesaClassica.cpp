#include "MesaClassica.hpp"

#include <iostream>

MesaClassica::MesaClassica():Mesa::Mesa() {}

MesaClassica::~MesaClassica() {}

void MesaClassica::set_preco(int preco) 
{
  if( preco < 4000 )
  {
    preco += 4000;
    cout << "Preço baixo, reajuste automático para: R$"<< preco << '\n';
  }
  this->preco = preco;
}

void MesaClassica::apresentar() 
{
  cout << "\n\tMesa clássica:\n";
  Mesa::apresentar();

}
