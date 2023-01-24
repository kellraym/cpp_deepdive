#include <iostream>

int* return_array(int length)
{
    return new int[length];
}

int main()
{

    int* my_arr = return_array(10);
    for (int i = 0; i < 10; i++)
    {
        my_arr[i] = i + 1;
    }
    std::cout << my_arr[2];
    delete my_arr;
}