#include <iostream>

// [capture_list](parameter_list)->return type {body}

// int my_func(int x, int y)
// {
//     return x + y;
// }

template<typename T>
void fun1(T f)
{
    f();
}

int main()
{
    // int (*fp)(int, int) = &my_func;
    auto f = [](){std::cout << "Hello\n";};
    f();

    [](int x, int y)
    {
        std::cout << "Sum: " << x + y << "\n";
    }(10, 5);

    int a = 10;
    int b = 5;
    [a, b](){std::cout << a << " " << b << std::endl;}(); // put out of scope vars into capture list
    auto fun2 = [&a, &b](){a++; b++;}; // put reference vars into capture list

    fun1(fun2);
    std::cout << a << " " << b << std::endl;
    return 0;
}