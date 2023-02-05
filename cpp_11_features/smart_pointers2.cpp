#include <iostream>
#include <memory>

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

int main()
{
    std::unique_ptr<Rectangle> ptr(new Rectangle(10, 5));
    std::cout << ptr->area() << std::endl;

    std::unique_ptr<Rectangle> ptr2;
    ptr2 = move(ptr); // assigns unique pointer to new pointer location, deallocates ptr
    // std::cout << ptr->area(); // can't do this now

    std::shared_ptr<Rectangle> ptr3(new Rectangle(11, 6));
    std::shared_ptr<Rectangle> ptr4(ptr3);

    std::cout << ptr3->area() << " " << ptr4->area() << std::endl;

    std::cout << ptr3.use_count() << std::endl;

    return 0;
}