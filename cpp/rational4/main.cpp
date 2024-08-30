#include <iostream>
#include "rational.h"

int main()
{
    Rational r1;            // 0 / 1
    Rational r2 = 3;        // 3 / 1
    Rational r3(3, 4);      //
    const Rational r4 = r3;       // rational r4(r3)

    r1 = r3;                // r1.operator = (r3) or operator = (r1, r3)

    Rational *pr = &r1;
    const Rational *pr2 = &r4;

    if(r1 == r3){       // r1.operator == (r3) or operator == (r1, r3)
        std::cout << "r1 and r3 are equal" << std::endl;
    } else {
        std::cout << "r1 and r3 are not equal" << std::endl;
    }

    r1 != r3;

    r2 = r1 + r2;
    r2 += r1;  

    r1++;
    ++r2;

    std::cout << "r1 : " << r1.getNum() << "/" << r1.getDen() << std::endl;
    std::cout << "r2 : " << r2 << std::endl;
    std::cout << "r3 : " << r3 << std::endl;
    std::cout << "r4 : " << r4 << std::endl;

    Rational r5;

    std::cout <<"input r5 : ";
    std::cin >> r5;                         // std::cin.operator(r5) 사용 불가 operator >> (std::cin, r5) 사용

    std::cout << "r5 : " << r5 << std::endl;

    return 0;
}