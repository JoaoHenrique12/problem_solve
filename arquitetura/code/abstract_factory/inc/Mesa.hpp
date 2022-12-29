#ifndef MESA_HPP
#define MESA_HPP

#include <utility>
#include <tuple>
using namespace std;

class Mesa {
  public:
    int preco;
    int n_pratos;
    pair<int,int> dimensoes;
    tuple<int,int,int> cor_rgb;

    Mesa();
    ~Mesa();

    virtual void apresentar();
    virtual void set_preco(int preco);

 private:
};

#endif  // MESA_HPP
