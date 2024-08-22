#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

void initList(List *pList, int eleSize)
{
    // pList -> ptr = malloc(sizeof(Node));            // dummy.
    pList -> ptr = malloc(sizeof(Node)/* + eleSize*/); 
    assert(pList -> ptr );
    // data X
    pList -> ptr -> next = NULL;
    pList -> eleSize = eleSize;
}
void cleanupList(List *pList)
{
    Node *p = pList -> ptr;

    while (p )
    {
        Node *tmp = p;
        p = p -> next;
        free(tmp);
    }
}

void insertFirstNode(List *pList, const void *pData)
{
    // Node *p = malloc(sizeof(Node));
    Node *p = malloc(sizeof(Node) + pList -> eleSize);
    assert(p );
    // p -> data = data;
    memcpy(p + 1, pData, pList -> eleSize);
    p -> next = pList -> ptr -> next;
    pList -> ptr -> next = p;
}

void insertNode(List *pList, const void *pPrevData, const void *pData)
{
    Node *ptr = pList -> ptr -> next;
    while (ptr )    
    {
        //if(ptr -> data == prevData)
        if(memcmp(ptr + 1, pPrevData, pList -> eleSize) == 0)
        {
            break;
        }
        ptr = ptr -> next;
    }

    if(ptr )        // found!
    {
        Node *p = malloc(sizeof(Node) + pList -> eleSize);
        assert(p );
        // p -> data = data;
        memcpy(p + 1, pData, pList -> eleSize);
        p -> next = ptr -> next;
        ptr -> next = p;
    }
    
}
void deleteNode(List *pList, const void *pData)
{
    Node *ptr1 = pList -> ptr -> next;
    Node *ptr2 = pList -> ptr;

    while (ptr1 )
    {
        // if (ptr1 -> data == data)
        if(memcmp(ptr1 + 1, pData, pList -> eleSize) == 0)
        {
            break;
        }
        
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    if (ptr1 )
    {
        ptr2 -> next = ptr1 -> next;
        free(ptr1);
    }
}

void printList(const List *pList, void (*print)(const void *))
{
    Node *p = pList -> ptr -> next;
    printf("[");
    while (p )
    {
        // printf("%d", p -> data);
        (*print)(p + 1);                            // == print(p + 1);
        printf( (p -> next) ? ", " : "]\n");
        p = p -> next;
    }
}