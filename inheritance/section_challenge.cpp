#include <iostream>

class Employee
{  
    private:
        int id;
        std::string name;
    
    public:
        Employee(int id, std::string name)
        {
            this->setId(id);
            this->setName(name);
        }

        int getId(int id)
        {
            return this->id;
        }

        std::string getName()
        {
            return this->name;
        }

        void setId(int id)
        {
            this->id = id;
        }

        void setName(std::string name)
        {
            this->name = name;
        }
};

class FullTimeEmployee: public Employee
{
    private:
        int salary;
    
    public:
        FullTimeEmployee(int id, std::string name, int salary): Employee(id, name)
        {
            this->salary = salary;
        }

        int getSalary()
        {
            return this->salary;
        }

        void setSalary(int salary)
        {
            this->salary = salary;
        }
};

class PartTimeEmployee: public Employee
{
    private:
        int hourlyWage;

    public:
        PartTimeEmployee(int id, std::string name, int hourlyWage): Employee(id, name)
        {
            this->hourlyWage = hourlyWage;
        }

        int getHourlyWage()
        {
            return this->hourlyWage;
        }

        void setHourlyWage(int hourlyWage)
        {
            this->hourlyWage = hourlyWage;
        }
};

int main()
{
    PartTimeEmployee p1(1, "John", 300);
    FullTimeEmployee p2(2, "Raj", 5000);

    std::cout << "Salary of " << p2.getName() << " is " << p2.getSalary() << std::endl;
    std::cout << "Daily wage of " << p1.getName() << " is " << p1.getHourlyWage() << std::endl;

    return 0;
}