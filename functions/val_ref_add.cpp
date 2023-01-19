#include <iostream>

void swap_val(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_address(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_reference(int& a, int& b) 
// a and b are references to input values, changing them in the function changes them in real life
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
    int x = 10, y = 15;
    swap_val(x, y);
    std::cout << x << " " << y << std::endl;
    swap_address(&x, &y);
    std::cout << x << " " << y << std::endl;
    swap_reference(x, y);
    std::cout << x << " " << y << std::endl;

    int& z = x; // z is a reference to x
    x = 30;
    std::cout << z << std::endl;
    return 0;
}