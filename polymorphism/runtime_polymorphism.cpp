#include <iostream>

class Car
{
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
};

class BigOlTruck: public Car
{
    public:
        void start()
        {
            std::cout << "Big ol truck startin\n";
        }
        
        void stop()
        {
            std::cout << "Bil ol truck stoppin\n";
        }
};

class SmallerTruck: public Car
{
    public:
        void start()
        {
            std::cout << "Lil truck startin\n";
        }

        void stop()
        {
            std::cout << "Lil truck stoppin\n";
        }
};

int main()
{
    Car *p1 = new BigOlTruck();
    Car *p2 = new SmallerTruck();
    // Car *p3 = new Car(); cannot instantiate abstract (purely virtual) class

    p1->start();
    p2->stop();

    return 0;
}