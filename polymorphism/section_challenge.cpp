#include <iostream>
#define PI 3.14159

template <class T>
class Shape
{
    public:
        virtual T area() = 0;
        virtual T perimeter() = 0;
};

class Rectangle: public Shape<int> // could be a float too, just demonstrating template class capability
{
    private:
        int length;
        int width;
    
    public:

        Rectangle(int length=0, int width=0)
        {
            this->setLength(length);
            this->setWidth(width);
        }

        void setLength(int length)
        {
            this->length = length;
        }

        void setWidth(int width)
        {
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

class Circle: public Shape<float>
{
    private:
        float radius;

    public:

        Circle(float radius)
        {
            this->setRadius(radius);
        }

        void setRadius(float radius)
        {
            this->radius = radius;
        }

        float area()
        {
            return PI * radius * radius ;
        }

        float perimeter()
        {
            return 2 * PI * radius;
        }
};

int main()
{
    Shape<int> *p1 = new Rectangle(4, 7);
    Shape<float> *p2 = new Circle(6);

    std::cout << p1->area() << std::endl;
    std::cout << p1->perimeter() << std::endl;

    std::cout << p2->area() << std::endl;
    std::cout << p2->perimeter() << std::endl;
    return 0;
}