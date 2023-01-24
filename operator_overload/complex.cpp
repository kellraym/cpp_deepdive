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

        Complex add(Complex c) // as a function
        {
            Complex new_c(this->real + c.real, this->imaginary + c.imaginary);
            return new_c;
        }

        Complex operator+(Complex c) // overloaded operator, r-value is the function input
        {
            return Complex(this->real + c.real, this->imaginary + c.imaginary);
        }

        Complex operator-(Complex c)
        {
            return Complex(this->real - c.real, this->imaginary - c.imaginary);
        }

        void print_complex()
        {
            if (this->imaginary > 0)
                std::cout << this->real << " + " << this->imaginary << "i" << std::endl;
            else
                std::cout << this->real << " - " << -(this->imaginary) << "i" << std::endl;
        }
};

int main()
{
    Complex c1(2, 3);
    Complex c2(5, 4);
    Complex c3 = c1.add(c2);
    Complex c4 = c1 + c2;
    Complex c5 = c1 - c3;

    c3.print_complex();
    c4.print_complex();
    c5.print_complex();
    return 0;
}