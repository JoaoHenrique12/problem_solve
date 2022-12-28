#ifndef CADEIRA_HPP
#define CADEIRA_HPP

class Cadeira {
  public:
    int peso;
    int preco;
    int n_pernas;
    bool alguem_esta_sentado;

    Cadeira();
    Cadeira(int peso,int n_pernas, bool alguem_esta_sentado);

    ~Cadeira(){};

    virtual void apresentar();
    virtual void set_preco(int preco);


    void sentar();
    void levantar();

};

#endif
