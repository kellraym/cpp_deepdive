#include <iostream>

class Complex
{
    private:
        int real;
        int imaginary;

    public:
        Complex(int real=0, int imaginary=0)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        friend std::ostream& operator<<(std::ostream &o, Complex &c1);
};

// must be a friend function, takes two argumants - the output stream and the object it is displaying
std::ostream& operator<<(std::ostream &o, Complex &c1) // also works as a void return but prevents further use of insertion op
{
        o << c1.real << "+i" << c1.imaginary;
        return o;
}

int main()
{   
    Complex c1(6, 4);
    std::cout << c1 << std::endl;
    operator<<(std::cout, c1);

    return 0;
}