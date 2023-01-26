#include <iostream>

class Base
{
    public:
        Base()
        {
            std::cout << "Default base constructor" << std::endl;
        }

        Base(int x)
        {
            std::cout << "Parameterized base constructor " << x << std::endl;
        }
};

class Derived: public Base
{
    public:
        Derived()
        {
            std::cout << "Default derived constructor" << std::endl;
        }
        
        Derived(int a)
        {
            std::cout << "Parameterized derived constructor " << a << std::endl;
        }

        Derived(int x, int a): Base(x) // pass x to Base constructor, use non-default base class constructor
        {
            std::cout << "Parameterized derived constructor " << a << std::endl;
        }
};

int main()
{
    Derived d;
    Derived d2(10);
    Derived d3(10, 5);
    return 0;
}