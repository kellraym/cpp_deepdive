#include <iostream>
#include <fstream>
#include <map>


// same as streams challenge but using a map instead of a dynamically allocated array
class Item
{
    private:
        std::string name;
        float price;
        int quantity;

    public:
        Item(){}
        Item(std::string n, float p, int q)
        {
            name = n;
            price = p;
            quantity = q;
        }

        friend std::ofstream &operator<<(std::ofstream &ofs, Item &i);
        friend std::ostream &operator<<(std::ostream &os, Item &i);
        friend std::ifstream &operator>>(std::ifstream &ifs, Item &i);
};

std::ofstream &operator<<(std::ofstream &ofs, Item &i)
{
    ofs << i.name << std::endl;
    ofs << i.price << std::endl;
    ofs << i.quantity << std::endl;
    return ofs;
}

std::ostream &operator<<(std::ostream &os, Item &i)
{
    os << i.name << std::endl;
    os << i.price << std::endl;
    os << i.quantity << std::endl;
    return os;
}

std::ifstream &operator>>(std::ifstream &ifs, Item &i)
{
    ifs >> i.name;
    ifs >> i.price;
    ifs >> i.quantity;
    return ifs;
}

int main()
{  
    int num_of_items;
    std::cout << "Enter number of items: ";
    std::cin >> num_of_items;

    // Item *item_arr = new Item[num_of_items];
    std::map<std::string, Item> item_map;

    for (int i = 0; i < num_of_items; i++)
    {
        std::string name;
        float price;
        int quantity;

        std::cout << "Item " << i + 1 << ": \n";
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter price: ";
        std::cin >> price;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        std::ofstream out_buffer("item_buffer.txt");
        
        out_buffer << name << std::endl;
        out_buffer << price << std::endl;
        out_buffer << quantity << std::endl;
        
        std::ifstream input;
        input.open("item_buffer.txt");
        input >> item_map[name];
        input.close();
    }
    std::map<std::string, Item>::iterator itr;
    std::ofstream write_list("item_list.txt");

    int i = 1;
    for (itr = item_map.begin(); itr != item_map.end(); itr++)
    {
        write_list << "Item " << i << "\n";
        write_list << itr->second;
        write_list << "\n";
    }

    write_list.close();

    std::ifstream read_list;
    read_list.open("item_list.txt");

    std::string list;

    while(!read_list.eof())
    {
        std::string temp;
        read_list >> temp;
        if (temp == "Item") list.append(temp + " ");
        else list.append(temp + "\n");
       
    }

    read_list.close();

    std::cout << list;
    // delete[]item_arr;
    return 0;
}