#ifndef CADEIRA_FUTURISTA_HPP
#define CADEIRA_FUTURISTA_HPP

#include "Cadeira.hpp"

class CadeiraFuturista: public Cadeira {
  public:
    CadeiraFuturista();
    ~CadeiraFuturista(){};
    void apresentar();
};

#endif
