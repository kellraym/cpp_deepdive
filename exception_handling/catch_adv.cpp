#include <iostream>

int divide(int x, int y)
{
    if (y == 0) throw 1;
    return x / y;
}

float divide(float x, float y)
{
    if (y == 0) throw 1.0f;
    return x / y;
}

void throws_error()
{
    throw "Hello";
}

int main()
{
    try
    {
        divide(4, 5);
        divide(5.6f, 2.0f);
        throws_error();
    }
    catch(int e)
    {
        std::cout << "integer error\n";
    }
    catch(float e)
    {
        std::cout << "float error\n";
    }
    catch(...) // use ellipses for general error catch, no type specified
    {
        std::cout << "general error\n";
    }

    std::cout << "done";   

    return 0;
}