#include <iostream>
#include "complex.h"

int main()
{
    Complex c1(3.0, 4.0);           // (3.0, 4.0i)
    Complex c2(3.0);                // (3.0, 0.0i)
    Complex c3;                     // (0.0, 0.0i)

    c3.real(c1.real());
    c3.imag(c1.imag());

    if(c1.real() == c3.real() && c1.imag() == c3.imag()){
        std::cout << "c1 and c3 are equal" << std::endl;
    } else{
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;

    return 0;
}