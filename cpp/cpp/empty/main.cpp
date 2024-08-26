#include "empty.h"

int main()
{
    Empty e1;
    const Empty e2 = e1;

    e1 = e2;

    Empty* pe = &e1;            // e1.operator&()

    const Empty* pe2 = &e2;     // e2.operator&()

    return 0;
}