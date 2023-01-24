
#include <iostream>

class Rectangle
{
    private:
        int length;
        int width;

    public:
        // Rectangle() // default constructor
        // {
        //     length = 0;
        //     width = 0;
        // }

        // compiler knows that its a constructor because of the function name, no return type needed
        Rectangle(int l=0, int w=0) // parameterized constructor, also default
        {
            setLength(l);
            setWidth(w);
        }

        Rectangle(Rectangle &r) // copy constructor (pass a reference to avoid copying a new object from argument)
        {
            length = r.length; // you can do this because you are inside the class right now;
            width = r.width;
        }

        void setLength(int l)
        {
            if (l > 0) length = l;
            else length = 0;
        }

        void setWidth(int w)
        {
            if (w > 0) width = w;
            else width = 0;
        }

        int getLength()
        {
            return length;
        }

        int getWidth()
        {
            return width;
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
    Rectangle r;
    Rectangle t(2, 3);
    Rectangle b(t);

    std::cout << r.getLength() << std::endl;
    std::cout << t.getWidth() << std::endl;
    std::cout << b.getWidth() << std::endl;
    return 0;
} 