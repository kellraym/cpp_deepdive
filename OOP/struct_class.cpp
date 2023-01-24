#include <iostream>

struct Demo // everything public by default, private by default in class, otherwise they are the same in c++
{
    int x;
    int y;

    void Display()
    {
        std::cout << x << " " << y << std::endl;
    }
};

int main()
{
    Demo d;
    d.x = 10;
    d.y = 20;
    d.Display();
    return 0;
}