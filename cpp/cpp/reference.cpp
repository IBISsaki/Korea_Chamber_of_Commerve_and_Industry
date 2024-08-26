#include <iostream>

int main()
{
    int a = 100;
    int &ra = a;

    ra = 200;           // a = 200;

    std::cout << "a : " << ra << std::endl;
    return 0;
}