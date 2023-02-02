#include <vector>
#include <iostream>

int main()
{
    // vector member functions mostly interchangeable with list, forward_list, set, etc.
    std::vector<int> v = {10, 20, 40, 90}; // will be of size 16 if not specified
    v.push_back(25);
    v.push_back(70);
    v.pop_back();
    
    for (int x: v)
    {
        std::cout << x << std::endl;
    }

    std::vector<int>::iterator itr;

    for (itr = v.begin(); itr != v.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }
    
    return 0;
}