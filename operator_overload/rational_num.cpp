#include <iostream>

class Rational
{
    private:
        int p;
        int q;

    public:
        Rational(int p=1, int q=1)
        {
            this->p = p;
            this->q = q;
        }

        Rational(Rational &r)
        {
            this->p = r.p;
            this->q = r.q;
        }

        void setP(int p)
        {
            this->p = p;
        }

        void setQ(int q)
        {
            this->q = q;
        }

        friend Rational operator+(Rational r1, Rational r2);
        friend std::ostream& operator<<(std::ostream &o, Rational &r);
};

Rational operator+(Rational r1, Rational r2)
{
    Rational t;
    t.setP(r1.p * r2.q + r2.p * r1.q);
    t.setQ(r1.q * r2.q);
    return t;
}

std::ostream& operator<<(std::ostream &o, Rational &r)
{
    o << r.p << "/" << r.q;
    return o;
}

int main()
{
    Rational r1(4, 5), r2(3, 4), r3;
    r3 = r1 + r2;
    // Rational r4(r1 + r3); // using reference constructor (doesn't work?)

    std::cout << r1 << " + " << r2 << " = " << r3 << std::endl;
    // std::cout << r1 << " + " << r3 << " = " << r4 << std::endl;
    return 0;
}