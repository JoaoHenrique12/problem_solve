#ifndef MESAFUTURISTA_HPP
#define MESAFUTURISTA_HPP

#include "Mesa.hpp"

class MesaFuturista: public Mesa {
  public:
    MesaFuturista();
    ~MesaFuturista();

    void apresentar();
    void set_preco(int preco);
  private:
};

#endif  // MESAFUTURISTA_HPP
