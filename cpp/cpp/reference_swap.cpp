#include <iostream>

void swap(int &ra, int &rb)         // call by reference
{
    int tmp;
    tmp = ra;
    ra = rb;
    rb = tmp;
}

int main()
{
    int a = 100;
    int b = 200;

    int &ra = a;
    int &rb = b;

    swap(a, b);

    std::cout << "a : " << ra << "\t" << "b : " << rb << std::endl;

    return 0;
}