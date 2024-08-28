#include <iostream>
#include "string.h"

int main()
{
    String s1;
    String s2 = "hello";
    String s3 = s2;

    s1 = s3;        // Deep copy

    if (s1 == s3){
        std::cout << "s1 and s3 are equal" << std::endl;
    } else {
        std::cout << "s1 and s3 are not equal" << std::endl;
    }

    String s4 = ", world";

    s1 = s2 + s4;

    std::cout << "s1 :  " << s1.c_str() << std::endl;
    std::cout << "s1 len :  " << s1.length() << std::endl;

    std::cout << "s2 : " << s2 << std::endl;
    std::cout << "s3 : " << s3 << std::endl;

    return 0;
}