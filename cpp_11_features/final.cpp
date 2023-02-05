#include <iostream>

class Parent // final // restricts inheritance
{
    virtual void show() final
    {
        //
    }
};

class Child: Parent
{
    // void show() final restricts inheritance and overriding
    // {

    // }
};

int main()
{

    return 0;
}