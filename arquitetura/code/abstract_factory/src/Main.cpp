#include<iostream>
#include<stdio.h>

#include "Cadeira.hpp"
#include "CadeiraClassica.hpp"
#include "CadeiraFuturista.hpp"

#include "Mesa.hpp"
#include "MesaClassica.hpp"
#include "MesaFuturista.hpp"

using namespace std;

int main()
{
  Cadeira c = Cadeira(50,3,true);
  c.apresentar();

  Cadeira* c2 = new CadeiraClassica();
  c2->set_preco(9);

  c2->apresentar();

  Cadeira* c3 = new CadeiraFuturista();
  c3->set_preco(12);
  c3->apresentar();

  Mesa m = Mesa();
  m.preco = 10;
  m.dimensoes = make_pair(3,5);

  m.apresentar();

  Mesa* m2 = new MesaClassica();

  m2->set_preco(40);
  m2->apresentar();

  Mesa* m3 = new MesaFuturista();

  m3->set_preco(40000);
  m3->apresentar();

  return 0;
}
