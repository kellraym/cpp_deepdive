#include <iostream>
#include <fstream>

class Student
{
    public:
        std::string name;
        int roll;
        std::string branch;

        friend std::ofstream &operator<<(std::ofstream &ofs, Student &s);
        friend std::ifstream &operator>>(std::ifstream &ofs, Student &s);
};

std::ofstream &operator<<(std::ofstream &ofs, Student &s)
{
    ofs << s.name << std::endl;
    ofs << s.roll << std::endl;
    ofs << s.branch << std::endl;
    return ofs;
}

std::ifstream &operator>>(std::ifstream &ifs, Student &s)
{
    ifs >> s.name;
    ifs >> s.roll;
    ifs >> s.branch;
    return ifs;
}

int main()
{
    Student s1;

    std::ifstream ifs("Student.txt");
    ifs >> s1;
    std::cout << s1.name;
    // s1.name = "John";
    // s1.roll = 10;
    // s1.branch = "CS";

    // std::ofstream ofs("Student.txt", std::ios::trunc);
    // ofs << s1;

    return 0;
}