#include <iostream>

class Demo
{
    public:
        int x = 10;
        int y = 20;

        // add const on first line to prevent modification of any member vars
        void Display() // const
        {
            x++; //  cannot do this with const keyword
            std::cout << x << " " << y << std::endl;
        }
};

void fun(const int &x, int &y)
{
    // x++; //cannot do this
    int a = x;
    a++; // this is fine 
}


int main()
{
    // const int x = 10;
    // // x++; can't do it
    // return 0;

    // int x = 10;
    // int y = 20;

    // usage 1 mutable pointer to a constant int
    // const int *ptr = &x; // value cannot be mutated through pointer
    // x = 20; // yes
    // ptr = &y; // yes
    // ++*ptr; // no

    // usage 2 mutable pointer to an immutable int
    // int const *ptr = &x; // essentially the same as usage 1
    // x = 20; // yes
    // ptr = &y; // yes
    // (*ptr)++; //no

    // usage 3 const pointer to a mutable int
    // int *const ptr = &x; // pointer is constant, value CAN be mutated through pointer
    // x = 20; // yes
    // ptr = &y; // no
    // ++*ptr; // yes

    // usage 4 const pointer to a const int
    // const int *const ptr = &x; // ptr cannot be mutated, value cannot be mutated through pointer
    // x = 20; //yes
    // *ptr = 20; // no
    // ptr = &y; // no

}