#include <iostream>

class Base
{
    public:
        virtual void fun1()
        {
            std::cout << "Base fun1\n";
        }

        virtual void fun2() = 0;
};

class Derived: public Base
{
    public:
        void fun2()
        {
            std::cout << "Derived fun2\n";
        }
};

int main()
{
    Base *p = new Derived();
    p->fun1();
    p->fun2();
    return 0;
}