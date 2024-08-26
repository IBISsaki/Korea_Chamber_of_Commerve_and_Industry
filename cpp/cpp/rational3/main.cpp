#include <iostream>
#include "rational.h"

int main()
{
    Rational r1;            // 0 / 1
    Rational r2 = 3;        // 3 / 1
    Rational r3(3, 4);      //
    Rational r4 = r3;       // rational r4(r3)

    
    r1 = r3;                // r1.operator = (r3) or operator = (r1, r3)


    if(r1 == r3){       // r1.operator == (r3) or operator == (r1, r3)
        std::cout << "r1 and r3 are equal" << std::endl;
    } else {
        std::cout << "r1 and r3 are not equal" << std::endl;
    }

    r1 != r3;

    Rational r5;
    r5 = r1 + r2;                                   // c5.operator = (c2,operator + (c3))

    Rational r6;
    r6 = r1 - r2;

    Rational r7;
    r7 = r1 * r2;

    Rational r8;
    r8 = r1 / r2;

    std::cout << "r1 : " << r1 << std::endl;
    std::cout << "r2 : " << r2 << std::endl;
    std::cout << "r3 : " << r3 << std::endl;
    std::cout << "r4 : " << r4 << std::endl;
    std::cout << "r5 : " << r5 << std::endl;
    std::cout << "r6 : " << r6 << std::endl;
    std::cout << "r7 : " << r7 << std::endl;
    std::cout << "r8 : " << r8 << std::endl;

    return 0;
}