#ifndef CADEIRA_CLASSICA_HPP
#define CADEIRA_CLASSICA_HPP

#include "cadeira.hpp"

class CadeiraClassica: public Cadeira {
  public:
    CadeiraClassica();
    ~CadeiraClassica(){};

    void apresentar();

    void set_preco(int preco);

};

#endif
