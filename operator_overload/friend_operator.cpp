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

        void display()
        {
            std::cout << this->real << "+i" << this->imaginary << std::endl;
        }

        friend Complex operator+(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2)
{
    Complex t;
    t.real = c1.real + c2.real;
    t.imaginary = c1.imaginary + c2.imaginary;
    return t;
}

int main()
{
    Complex c1(5, 3), c2(10, 5), c3;
    c3 = c1 + c2;
    c3.display();
    return 0;
}