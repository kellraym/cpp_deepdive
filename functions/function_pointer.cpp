#include <iostream>

void display()
{
    std::cout << "Hello";
}

int main()
{
    void (*fp)(); // fp is var name, fp is a function pointer
    fp = display;
    (*fp)();
    return 0;
}