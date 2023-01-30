#include <iostream>

class MyException: public std::exception
{
    public:
        std::string error;
        MyException(std::string error)
        {
            this->error = error;
        }
        // using the std lib exception
        std::string what()
        {
            return error;
        }
};

// int division(int x, int y) throw(MyException) // can be anything, but it's deprecated
// {
//     if (y == 0) throw MyException();
//     return x / y;
// }

int division(int x, int y)
{
    if (y == 0) throw MyException("Divide by zero error");
    return x / y;
}

int main()
{
    try
    {
        division(10, 0);
    }
    catch (MyException e)
    {
        std::cout << "bad: " << e.what();
    }

    std::cout << "\nMade it to the end";
    
    return 0;
}