#include <iostream>
#include <cstdarg>

int sum(int n, ...) // n is the number of parameters represented by ellipsis
{
    va_list list;
    va_start(list, n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += va_arg(list, int); //  retrieves each element of va_list, iterates
    }
    va_end(list);
    return s;
}

int main()
{
    std::cout << sum(5, 1, 2, 3, 4, 5);
    return 0;
}