#include<stdio.h>

#include "Cadeira.hpp"

Cadeira::Cadeira()
{
  this->peso = 1;
  this->n_pernas = 4;
  this->alguem_esta_sentado = false;
};

Cadeira::Cadeira(int peso,int n_pernas, bool alguem_esta_sentado)
{
  this->peso = peso;
  this->n_pernas = n_pernas;
  this->alguem_esta_sentado = alguem_esta_sentado;
};

void Cadeira::set_preco(int preco)
  { this->preco = preco; }

void Cadeira::sentar()
{ this->alguem_esta_sentado = true; }

void Cadeira::levantar()
{ this->alguem_esta_sentado = false; }

void Cadeira::apresentar()
{
  printf("\n\tA Cadeira\n");
  printf("Peso: %dkg\n", this->peso);
  printf("Número de pernas: %d\n",this->n_pernas);
  printf("Alguém está sentado: %s\n",this->alguem_esta_sentado? "Sim":"Não");
}
