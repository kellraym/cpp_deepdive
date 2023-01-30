#include <iostream>

template<class T>
class MyException: public std::exception
{
    private:
        T error_code;
        std::string error_msg;

    public:
        MyException(T error_val, std::string error_msg)
        {
            this->error_code = error_val;
            this-> error_msg = error_msg;
        }

        std::string getErrorMsg()
        {
            return error_msg;
        }

        const char *what()
        {
            std::string s("Error code " + std::to_string(error_code) + ": " + error_msg + "\n");
            return s.c_str();
        }
};

template<class T>
T divide(T x, T y)
{
    if (y == 0) throw MyException<T>(x, "Divide by zero error");
    return x / y;
}

int main() // didn't help as much as I expected, oh well
{
    try
    {
        divide(1.2f, 0.0f);
        divide(2, 4);
    }
    catch(MyException<float> e)
    {
        std::cout << e.what();
    }
    catch(MyException<int> e)
    {
        std::cout << e.what();
    }

    std::cout << "end";

    return 0;
}