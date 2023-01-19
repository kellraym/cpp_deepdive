#include <iostream>
template <class T>

T max(T x, T y)
{
    return x > y ? x : y;
}

int main()
{
    std::cout << max(3.4, 5.7) << std::endl;
    std::cout << max(1, 45) << std::endl;
}