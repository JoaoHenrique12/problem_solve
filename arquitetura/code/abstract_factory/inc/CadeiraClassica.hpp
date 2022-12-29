#ifndef CADEIRA_CLASSICA_HPP
#define CADEIRA_CLASSICA_HPP

#include "Cadeira.hpp"

class CadeiraClassica: public Cadeira {
  public:
    CadeiraClassica();
    ~CadeiraClassica(){};

    void apresentar();

    void set_preco(int preco);

  private:
};

#endif
