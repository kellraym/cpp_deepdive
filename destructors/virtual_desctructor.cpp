#include <iostream>

class Base
{
    public:
        Base()
        {
            std::cout << "Base constructor" << std::endl;
        }

        virtual ~Base()
        {
            std::cout << "Base desctructor" << std::endl;
        }
};

class Derived: public Base
{
    public:
        Derived()
        {
            std::cout << "Derived constructor" << std::endl;
        }

        ~Derived()
        {
            std::cout << "Derived destructor" << std::endl;
        }
};

int main()
{
    Base *p = new Derived();
    delete p; // only base destructor is called unless it is virtual
    return 0;
}