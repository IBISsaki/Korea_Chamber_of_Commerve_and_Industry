#include <cstdio>
#include <iostream>
#include "stack.h"

int main()
{
    Stack s1;
    Stack s2(20);

    //Stack s3 = s2;

    //s1 = s2;

    s1.push(100);
    s1.push(200);
    s1.push(300);

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;

    for(int i = 1; i <= 10; ++i)
    {
        if(!s2.isFull())
        {
            s2.push(i);
        }
    }

    while (!s2.isEmpty())
    {
        std::cout << s2.pop() << std::endl;      
    }
    
    s2.push(900);
    s2.push(800);
    s2.push(700);

    return 0;
}