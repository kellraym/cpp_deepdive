#include <iostream>

// #define MAX(x, y) (x > y ? x : y)
#define MAX(x, y, z) (x > y ? x > z ? x : z : y > z ? y : z);

int main()
{
    float maximum = MAX(4.255f, 7.812f, 3.214f);
    std::cout << maximum;
}