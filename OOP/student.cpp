#include <iostream>
#include <string>

class Student
{
    private:
        int roll;
        std::string name;
        int mathMarks;
        int phyMarks;
        int chemMarks;

    public:
        Student(int roll, std::string name, int m, int p, int c);
        int getMathMarks();
        void setRoll(int roll);
        void setName(std::string name);
        void setMathMarks(int m);
        void setPhysMarks(int p);
        void setChemMarks(int c); 
        int total();
        void grade();
        ~Student();
};

int main()
{
    int roll;
    std::string name;
    int math;
    int phys;
    int chem;

    std::cout << "Enter student roll number: ";
    std::cin >> roll;
    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cout << "Enter 3 grades: ";
    std::cin >> math >> phys >> chem;

    Student s(roll, name, math, phys, chem);
    std::cout << "Total grade: " << s.total() << std::endl;
    std::cout << "Grade: ";
    s.grade();

    return 0;
}

Student::Student(int roll, std::string name, int m, int p, int c)
{
    setRoll(roll);
    setName(name);
    setMathMarks(m);
    setPhysMarks(p);
    setChemMarks(c);
}

int Student::getMathMarks()
{
    return this->mathMarks;
}

void Student::setRoll(int roll)
{
    this->roll = roll;
}

void Student::setName(std::string name)
{
    this->name = name;
}

void Student::setMathMarks(int m)
{
    this->mathMarks = m;
}

void Student::setPhysMarks(int p)
{
    this->phyMarks = p;
}

void Student::setChemMarks(int c)
{
    this->chemMarks = c;
}

int Student::total()
{
    return this->mathMarks + this->phyMarks + this->chemMarks;
}

void Student::grade()
{
    double average = this->total() / 3.0;

    if (average >= 90) std::cout << "A" << std::endl;
    else if (average >= 80) std::cout << "B" << std::endl; 
    else if (average >= 70) std::cout << "C" << std::endl;
    else if (average >= 60) std::cout << "D" << std::endl;
    else std::cout << "F" << std::endl;
}

Student::~Student()
{
    std::cout << "Student deleted" << std::endl;
}