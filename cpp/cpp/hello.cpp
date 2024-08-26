#include <iostream>

int main()
{
    // std::cout << "hello, world";
    operator << (std::cout , "hello, world");
    // std::cout.operator << ("hello, world");

    // std::cout << std::endl;
    // operator << (std::cout, std::endl);
    std::cout.operator << (std::endl);

    // std::cout << "hello, world" << std::endl;
    operator << (std::cout , "hello, world").operator << (std::endl);               // 연산자 중복 (<<)


    return 0;
}

/*
operator overloading

a + b
--> a.operator+(b) or operator+(a + b)
*/