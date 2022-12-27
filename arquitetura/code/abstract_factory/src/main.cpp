#include<iostream>
#include<stdio.h>
#include "cadeira.hpp"
#include "cadeira_classica.hpp"
#include "cadeira_futurista.hpp"

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

  return 0;
}
