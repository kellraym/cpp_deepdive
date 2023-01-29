#include <iostream>

class Test
{
    private:
        int a;
        int b;
    
    public:
        static int count;
        Test()
        {
            a = 10;
            b = 10;
            count++;
        }

        static int getCount()
        {
            // a++; can't do this in here
            return count;
        }
};

int Test::count = 0; // must also declare and initialize outside the class, still only accessible to Test

int main()
{
    Test t1;
    std::cout << Test::count << std::endl;
    Test t2;
    std::cout << t1.count << std::endl; // can be accessed from class or objects of class
    std::cout << Test::getCount() << std::endl;
    return 0;
}