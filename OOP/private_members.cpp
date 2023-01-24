class Rectangle
{
    private:
        int length;
        int width;

    public:
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

    r.setLength(5);
    return 0;
}