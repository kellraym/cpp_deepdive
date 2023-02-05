#include <iostream>
#include <memory> // need this to make smart pointers work

class Rectangle
{
    private:
        int length;
        int width;

    public:
        Rectangle(int length, int width)
        {
            this->length = length;
            this->width = width;
        }

        int area()
        {
            return length * width;
        }

        int perimeter()
        {
            return 2 * (length + width);
        }
};

std::unique_ptr<int[]> fun() // also shared_ptr and weak_ptr
{
    std::unique_ptr<int[]> p1(new int[5]);
    return p1;
}

void make_rect()
{
    std::unique_ptr<Rectangle> p2(new Rectangle(10, 5));
    std::cout << p2->area() << std::endl;
    std::cout << p2->perimeter() << std::endl;
}

int main()
{
    make_rect();
    return 0;
}