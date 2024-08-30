#include <iostream>
#include "complex.h"
#include "stack.h"

int main()
{
    Stack<int> s1;    
    s1.push(100);
    s1.push(200);
    s1.push(300);

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;

    Stack<Complex> s2;
    s2.push(Complex(3.0, 4.0));
    s2.push(Complex(5.0, 6.0));
    s2.push(Complex(7.0, 8.0));

    std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
    std::cout << "s2 2nd pop() : " << s2.pop() << std::endl;
    std::cout << "s2 3rd pop() : " << s2.pop() << std::endl;

    return 0;
}