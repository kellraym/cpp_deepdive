#include <iostream>

class Your; // declare it first so it can be made a friend, then define later

class My
{
    private:
        int a = 10;
    
        friend Your; // a class can be a friend too
};

class Your // container class for My
{
    public:
        My m;

    void fun()
    {
        std::cout << m.a;
    }
};

int main()
{

    return 0;
}