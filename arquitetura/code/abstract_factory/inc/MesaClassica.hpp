#ifndef MESACLASSICA_HPP
#define MESACLASSICA_HPP

#include "Mesa.hpp"

class MesaClassica: public Mesa {
  public:
    MesaClassica();
    ~MesaClassica();

    void apresentar();
    void set_preco(int preco);

  private:
};

#endif  // MESACLASSICA_HPP
