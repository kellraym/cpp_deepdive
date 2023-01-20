#include <iostream>

int x = 10;

int main()
{
    int x = 20;
    std::cout << x << std::endl;
    std::cout << ::x << std::endl; // :: is scope resolution operator, :: by itself resolves the current file
    return 0;
}