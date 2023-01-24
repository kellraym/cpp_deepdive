#include <iostream>

class Test
{
    private:
        int a;
        int *p;

    public:
        Test(int x)
        {
            a = x;
            p = new int[a];
        }

        Test(Test &t)
        {
            a = t.a;
            // p = t.p; // this will point to the same location as input Test
            p = new int[a]; // allocate a new int array to the heap
            for (int i = 0; i < a; i++)
            {
                p[i] = t.p[i]; // copy p values over to newly allocated array
            }
        }
};