#include <iostream>

namespace first
{
    void fun()
    {
        std::cout << "First\n";
    }
}

namespace second
{
    void fun()
    {
        std::cout << "Second\n";
    }
}

using namespace first;

int main()
{
    fun();
    second::fun();
    return 0;
}