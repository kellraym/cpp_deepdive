#include <iostream>

int division(int x, int y)
{
    if (y == 0) throw 1; // throws to the outer try block
    return x / y;
}

int main()
{
    int a = 10, b = 0, c;

    try
    {
        c = division(a, b);
        std::cout << c << "\n";
    }
    catch (int e)
    {
        std::cout << "Division by zero: " << "error code " << e << "\n"; 
    }
    return 0;
}