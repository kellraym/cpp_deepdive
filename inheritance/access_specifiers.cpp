#include <iostream>

class Base
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;
    
        void funBase()
        {
            a = 10;
            b = 20;
            c = 30;
        }
};

class Derived: Base
{
    public:
        void funDerived()
        {
            // a = 1;
            b = 2; // protected available in child class
            c = 3;
        }
};

int main()
{
    Base x;
    // x.a = 15;
    // x.b = 30; // protected not accessible in main
    x.c = 90;
    return 0;
}