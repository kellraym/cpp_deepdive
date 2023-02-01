#include <fstream>
#include <iostream>

void check_input(std::ifstream input)
{
    if (!input) throw 1;
}

int main()
{
    //this stream moves stuff to the file from the program, will create new file or overwrite existing file
    std::ofstream outfile("my.txt");
    // to append to existing file
    // std::ofstream outfile2("my.txt", std::ios::app);
    // truncate contents, this is the default so outfile == outfile3
    // std::ofstream outfile3("my.txt", std::ios::trunc);

    outfile << "Hello\n";
    outfile << 25;
    outfile.close(); // don't forget to close your file stream

    std::ofstream appendfile("my.txt", std::ios::app);
    appendfile << "\nand";
    appendfile.close();

    std::ifstream infile;

    infile.open("my.txt"); // file must exist already, can't open otherwise

    if (!infile) 
    {
        std::cout << "File cannot be opened";
        return 1;
    }

    std::string str1;
    std::string str2;
    int x;
    infile >> str1; //  does it by space separated values
    infile >> x;
    infile >> str2;

    std::cout << str1 << " " << x << " " << str2 << std::endl;

    if (infile.eof())
    {
        std::cout << "End of file reached";
    }

    return 0;
}