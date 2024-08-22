#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// void printInt(int data)
void printInt(const void *pData)
{
    printf("%d", *(int *)pData);
}

// void printDouble(double data)
void printDouble(const void *pData)
{
    printf("%f", *(double*)pData);
}

int main(void)
{
    List list1, list2;                 
    initList(&list1, sizeof(int));
    initList(&list2, sizeof(double));

    int i;
    i = 4;          insertFirstNode(&list1, &i);
    i = 3;          insertFirstNode(&list1, &i);
    i = 1;          insertFirstNode(&list1, &i);
    int j = 1;
    i = 2;          insertNode(&list1, &j, &i);
    i = 3;          deleteNode(&list1, &i);
    printList(&list1, &printInt);

    double d;
    d = 4.4;        insertFirstNode(&list2, &d);
    d = 3.3;        insertFirstNode(&list2, &d);
    d = 1.1;        insertFirstNode(&list2, &d);
    double f = 1.1;
    d = 2.2;        insertNode(&list2, &f, &d);
    d = 3.3;        deleteNode(&list2, &d);
    printList(&list2, printDouble);

    cleanupList(&list1);
    cleanupList(&list2);

    return 0;
}