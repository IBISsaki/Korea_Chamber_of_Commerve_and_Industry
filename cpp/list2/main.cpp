#include <iostream>
#include "list.h"

int main()
{
    List list;                 

    list.insertFirstNode(4);
    list.print();               // [4]
    list.insertFirstNode(3);
    list.print();               // [3, 4]
    list.insertFirstNode(1);
    list.print();               // [1, 3, 4]

    list.insertNode(1, 2);
    list.print();               // [1, 2, 3, 4]    

    list.deleteNode(3);
    list.print();
    
    return 0;
}