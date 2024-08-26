#include <iostream>
#include "rational.h"

int main()
{
    Rational r1;            // 0 / 1
    Rational r2 = 3;        // 3 / 1
    Rational r3(3, 4);      //
    Rational r4 = r3;       // rational r4(r3) 

    // r1.setNum(r3.getNum());
    // r1.setDen(r3.getDen());
    r1 = r3;                // r1.operator = (r3) or operator = (r1, r3)

    // if(r1.getNum() == r3.getNum() && r1.getDen() == r3.getDen()){
    if(r1 == r3){       // r1.operator == (r3) or operator == (r1, r3)
        std::cout << "r1 and r3 are equal" << std::endl;
    } else {
        std::cout << "r1 and r3 are not equal" << std::endl;
    }

    std::cout << "r1 : " << r1.getNum() << "/" << r1.getDen() << std::endl;
    std::cout << "r2 : " << r2.getNum() << "/" << r2.getDen() << std::endl;
    std::cout << "r3 : " << r3.getNum() << "/" << r3.getDen() << std::endl;
    std::cout << "r4 : " << r4.getNum() << "/" << r4.getDen() << std::endl;

    return 0;
}