#include <iostream>

// Base class template
template<typename T>
class Base {
public:
    Base(const T& value) : data(value) {}

    void display() {
        std::cout << "Base: " << data << std::endl;
    }

protected:
    T data;
};

// Derived class from Base
template<typename T>
class Derived : public Base<T> {
public:
    Derived(const T& value) : Base<T>(value) {}

    void displayDerived() {
        std::cout << "Derived: " << this->data << std::endl; // Accessing data member of Base
    }
};

int main() {
    // Creating objects of Base and Derived classes with different data types
    Base<int> baseObj(10);
    baseObj.display();

    Derived<double> derivedObj(3.14);
    derivedObj.display();
    derivedObj.displayDerived();

    return 0;
}
