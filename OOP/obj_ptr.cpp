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
    Rectangle r;
    Rectangle* p;
    Rectangle* q;

    p = &r;
    q = new Rectangle;
    q->length = 30;
    q->width = 20;
    r.length = 10;
    p->length = 20;

    std::cout << r.length << std::endl;
    std::cout << q->area() << std::endl;

    delete q;

    return 0;
}