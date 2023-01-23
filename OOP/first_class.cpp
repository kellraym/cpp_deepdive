#include <iostream>

class Rectangle
{
    public:
        int length;
        int width;

        int area()
        {
            return length * width;
        }

        int perimeter()
        {
            return 2 * (length + width);
        }

};

int main()
{
    Rectangle r1, r2;
    r1.length = 10;
    r1.width = 5;

    r2.length = 15, r2.width = 10;

    std::cout << r1.area() << std::endl; 
    std::cout << r2.area() << std::endl;
    return 0;
}