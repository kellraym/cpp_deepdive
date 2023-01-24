#include <iostream>

class Rectangle
{
    private:
        int length;
        int width;

    public:
        // Rectangle(); // constructors
        Rectangle(int l, int b);
        Rectangle(Rectangle &r);
        void setLength(int l); // mutators
        void setWidth(int w);
        int getLength(); // accessors
        int getWidth();
        int area(); // facilitators
        int perimeter();
        bool isSquare(); // inspectors/enquiry
        ~Rectangle(); // destructor
};

int main()
{
    Rectangle r1(10, 10);
    std::cout << "Area " << r1.area() << std::endl;
    if (r1.isSquare())
    {
        std::cout << "Yes" << std::endl;
    }
    // destructor is called at the end of main automatically

    Rectangle *r2 = new Rectangle(5, 10);
    std::cout << "Area " << r2->area() << std::endl;
    if (!(r2->isSquare()))
    {
        std::cout << "No" << std::endl;
    }
    delete r2;
    return 0;
}

// Defining functions with scope resolution operator makes compiler create separate block of code for class functions

Rectangle::Rectangle(int length=1, int width=1)
{
    setLength(length);
    setWidth(width);
}

Rectangle::Rectangle(Rectangle &r)
{
    this->length = r.length;
    this->width = r.width;
}

void Rectangle::setLength(int length)
{
    if (length > 0) this->length = length;
    else this->length = 1;
}

void Rectangle::setWidth(int width)
{
    if (width > 0) this->width = width;
    else this->width = 1;
}

int Rectangle::getLength()
{
    return this->length;
}

int Rectangle::getWidth()
{
    return this->width;
}

int Rectangle::area()
{
    return this->length * this->width;
}

int Rectangle::perimeter()
{
    return 2 * (this->length + this->width);
}

bool Rectangle::isSquare()
{
    return this->length == this->width;
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle Destroyed" << std::endl;
}