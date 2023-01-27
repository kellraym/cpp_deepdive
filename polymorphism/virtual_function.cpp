#include <iostream>

class Base
{
    public:
        virtual void fun()
        {
            std::cout << "fun of Base" << std::endl;
        }
};

class Derived: public Base
{
    public:
        void fun()
        {
            std::cout << "fun of Derived" << std::endl;
        }
};

int main()
{
    Base *p = new Derived();
    p->fun(); // calls the derived function despite pointer type thanks to the virtual keyword

    Base *p2 = new Base();
    p2->fun();
    return 0;
}