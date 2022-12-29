#include "MesaFuturista.hpp"

#include <iostream>

MesaFuturista::MesaFuturista():Mesa::Mesa() {}

MesaFuturista::~MesaFuturista() {}

void MesaFuturista::set_preco(int preco)
{
  if( preco > 10000 )
  {
    preco -= 4000;
    cout << "Preço muito alto, redução para: R$"<< preco << '\n';
  }

  this->preco = preco;
}

void MesaFuturista::apresentar()
{
  cout << "\n\tOlha, uma mesa futurista ~~~~:\n";
  Mesa::apresentar();
}
