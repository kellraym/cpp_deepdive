#include <iostream>

int main()
{
    int a = 1, b = 0, c;

    try
    {
        {
            if (b == 0)
            {
                throw 1; // this is the argument for the catch block
            }
            c = a / b;
            std::cout << c;
        }
    }
    catch (int e)
    {
        std::cout << "Division by zero " << e << std::endl;
    }
    
    std::cout << "goodbye";
}