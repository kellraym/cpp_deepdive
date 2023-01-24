#include <iostream>

class Test
{
    public:
        void func()
        {
            std::cout << "Inline";
        }

        void func2();
};

void Test::func2()
{
    std::cout << "non-inline";
}

int main()
{
    Test t;
    t.func();
    t.func2();
}