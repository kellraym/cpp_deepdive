#include <iostream>

class Base
{
    public:
        void display()
        {
            std::cout << "Display base\n";
        }
};

class Derived: public Base{};

int main()
{
    Base b;
    b.display();
    Derived d;
    d.display();
    return 0;
}