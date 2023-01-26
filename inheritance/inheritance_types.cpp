#include <iostream>

class Parent
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;

        void funParent()
        {
            a = 10;
            b = 5;
            c = 15;
        }
};

class Child: public Parent
{
    public:
        void funChild()
        {
            // a = 10; // private in parent class
            b = 12;
            c = 15;
        }
};

class GrandChild: public Child
{
    public:
        void funGrandChild()
        {
            // a = 10; 
            b = 12; // changing Child to inherit privately will hide b and c from GrandChild
            c = 15;
        }
};

int main()
{
    Child c;
    // c.a = 10;
    // c.b = 15;
    c.c = 20;

    GrandChild g;
    // g.a = 10;
    // g.b = 20;
    g.c = 30;

    return 0;
}

