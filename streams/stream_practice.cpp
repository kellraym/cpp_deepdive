#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("my.txt");
    std::string name;
    int roll;
    std::string branch;
    
    if (ifs.is_open())
    {
        std::cout << "File is opened" << std::endl;
    }
    ifs >> name >> roll >> branch;
    ifs.close();

    std::cout << "Name " << name << std::endl;
    std::cout << "Roll " << roll << std::endl;
    std::cout << "Branch " << branch << std::endl;
    return 0;
}