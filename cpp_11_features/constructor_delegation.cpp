#include <iostream>

class Test
{
    private:
        int x = 10;
        int y = 13;

    public:
        Test(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        Test(): Test(1, 1) // calling constructor with no parameters delegates to the parameterized constructor
        {}
};

int main()
{

    return 0;
}