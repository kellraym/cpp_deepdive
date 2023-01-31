#include <iostream>
#include <fstream>

class Test
{
    private:
        int *p;
        std::ifstream fis; 

    public:
    Test()
    {
        p = new int[10]; // must be deleted when object is destroyed
        fis.open("my.text"); // must be closed on object destruction
        std::cout << "Test created\n";
    }

    ~Test()
    {
        delete[]p;
        fis.close();
        std::cout << "Test terminated\n";                           
    }
};

int main()
{
    Test *pt = new Test();
    delete pt;

    Test t;
    return 0;
}