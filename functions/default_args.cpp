#include <iostream>
template <class T>

T add(T x, T y, T z = 0)
{
    return x + y + z;
}

template <class T>
float divide(T x, T y)
{
    return (float) x / y;
}

int main()
{
    std::cout << add(1, 2, 3) << std::endl;
    std::cout << add(1.2, 4.5) << std::endl;
    std::cout << divide(6, 5) << std::endl;
    std::cout << divide(1.2, 5.3) << std::endl;
    return 0;
}