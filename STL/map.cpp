#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> m;
    m.insert(std::pair<int, std::string>(1, "Hello"));
    m.insert(std::pair<int, std::string>(2, "there"));
    m.insert(std::pair<int, std::string>(3, "man"));

    std::map<int, std::string>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++);
    {
        std::cout << itr->first << std::endl;
    }

    // itr = m.begin();
    // std::cout << itr->first << " " << itr->second << std::endl;

    std::cout << m[2] << std::endl;

    return 0;
}