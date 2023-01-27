#include <iostream>

class Parent
{
    public:
        void display()
        {
            std::cout << "Parent display" << std::endl;
        }
};

class Child: public Parent
{
    public:
        void display()
        {
            std::cout << "Child display" << std::endl;
        }
};

int main()
{
    Parent p;
    p.display();

    Child c;
    c.display();

    c.Parent::display();

    return 0;
}