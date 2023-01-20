#include <iostream>

int& fun(int& x)
{
    return x;
}

int main()
{
    int a = 10;
    fun(a) = 25; //what!?
    std::cout << a << std::endl;
    return 0;
}