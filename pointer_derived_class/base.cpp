class Base
{
    public:
        void fun1();
        void fun2();
        void fun3();
};

class Derived: public Base
{
    public:
        void fun4();
        void fun5();
};

int main()
{
    Base *p;
    p = new Derived();
    p->fun1();
    p->fun2();
    p->fun3();
    // p->fun4(); pointer to base class has no space allocated for dervied functions

    // Derived *p2; 
    // p2 = new Base(); // doesn't work this way

    delete p;
    return 0;
}