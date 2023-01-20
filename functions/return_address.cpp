#include <iostream>

int* make_int_arr(int size)
{
    int* p = new int[size];
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p;
}

int main()
{
    int* arr = make_int_arr(5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    delete[]arr;
    arr = nullptr;
    return 0;
}