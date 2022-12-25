#include<iostream>
using namespace std;
  
// Virtual fala pra a instância da classe usar a sobrescrita de objetos filhos.
// virtual void print() = 0; -> Não deixa implementar na classe base.
class base {
  public:
    virtual void print()
      { cout << "print base class\n"; }
  
    void show()
      { cout << "show base class\n"; }
};
  
class derived : public base {
public:
    void print()
      { cout << "print derived class\n"; }
  
    void show()
      { cout << "show derived class\n"; }
};
  
int main()
{
    base *bptr;
    derived d;
    bptr = &d;
  
    // Virtual function, binded at runtime
    bptr->print();
  
    // Non-virtual function, binded at compile time
    bptr->show();
    
    return 0;
}
