#include "Mesa.hpp"

#include<iostream>
#include<stdio.h>

using namespace std;

Mesa::Mesa() 
{
  this->preco = 500;
  this->n_pratos = 4;
  this->dimensoes = make_pair(2,5);
  this->cor_rgb = make_tuple(244,100,35);
}

Mesa::~Mesa() {}

void Mesa::set_preco(int preco) {}

void Mesa::apresentar()
{
  cout << "\n\tMesa\n";
  cout << "Preço: R$ " << this->preco << "\n";
  cout << "Dimensões: " << this->dimensoes.first << "m x "<<\
           this->dimensoes.second << "m\n";
  cout << "Número de pratos na mesa: " << this->n_pratos << "\n";
  printf("Cor da mesa em rgb: (%d,%d,%d)\n",
          get<0>(this->cor_rgb),
          get<1>(this->cor_rgb),
          get<2>(this->cor_rgb));
}
