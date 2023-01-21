#include <iostream>
#include <cstring>

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int (*fp)(int, int);
    int num1;
    int num2;
    char choice[4];
    std::cout << "Enter max or min: ";
    std::cin >> choice;
    std::cout << "Enter two numbers: ";
    std::cin >> num1;
    std::cin >> num2;
    if (strcmp(choice, "max") == 0)
    {
        fp = max;  
    }
    else if (strcmp(choice, "min") == 0)
    {
        fp = min;
    }
    else
    {
        std::cout << "You did it wrong";
        return -1;
    }

    std::cout << (*fp)(num1, num2);

    return 0;
}