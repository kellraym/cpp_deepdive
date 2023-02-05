#include <iostream>

float fun()
{
    return 2.34f;
}

int main()
{
    auto x = 2 * 5.7 + 'a';
    std::cout << x;

    auto y = fun();

    decltype(y) z = 3.4f; // use the type of another var to declare a new one
    return 0;
}