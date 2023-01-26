#include <iostream>

class Rectangle
{
    private:
        int length;
        int width;

    public:
        Rectangle(int l=0, int w=0);
        Rectangle(Rectangle &r);
        int getLength();
        int getWidth();
        void setLength(int l);
        void setWidth(int w);
        int area();
        int perimeter();
        ~Rectangle();
};

class Cuboid: public Rectangle
{
    private:
        int height;
    
    public:
        Cuboid(int l=0, int w=0, int h=0)
        {
            this->height = h;
            setLength(l);  // cannot access private member vars from parent, user setter
            setWidth(w);
        }

        int getHeight();
        void setHeight(int h);
        int volumn()
        {
            return this->getLength() * this->getWidth() * this->height;
        }
};

int main()
{
    Cuboid c(10, 5, 3);

    return 0;
}