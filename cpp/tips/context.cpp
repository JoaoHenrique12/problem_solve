#include <iostream>

// A global variable
int x = 10;

// A namespace
namespace MyNamespace {
    int x = 20;
}

class MyClass {
public:
    static int my_static_var;
    enum Colors { RED, GREEN, BLUE };

    void print_vars() {
        int x = 30; // A local variable

        // Accessing the local variable
        std::cout << "Local x: " << x << std::endl;

        // Accessing the global variable
        std::cout << "Global x: " << ::x << std::endl;

        // Accessing the namespace variable
        std::cout << "Namespace x: " << MyNamespace::x << std::endl;

        // Accessing the static class member
        std::cout << "Static var: " << MyClass::my_static_var << std::endl;

        // Accessing the nested enum value
        std::cout << "Color: " << MyClass::Colors::BLUE << std::endl;
    }
};

int MyClass::my_static_var = 50;

int main() {
    MyClass obj;
    obj.print_vars();
    return 0;
}
