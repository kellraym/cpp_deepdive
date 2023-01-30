#include <iostream>

#define PI 3.145
#define C std::cout
#define SQR(x) (x * x)
#define MSG(x) #x //wraps x in quotes
#define print(x) (printf(#x))

int main()
{
    int x = 24;
    C << PI << "\n";
    C << SQR(30) << "\n";
    C << MSG(THIS IS NOT A STRING) << "\n";
    C << MSG(SQR(5)) << "\n";
    C << MSG(x) << "\n"; // wraps input in quotes, not the value of the input
    print(hello);
    return 0;
}