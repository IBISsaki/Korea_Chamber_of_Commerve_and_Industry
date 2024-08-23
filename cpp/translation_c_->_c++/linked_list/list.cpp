#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

static Node::Node *createNode(int data)
{
    Node *p = (int *)malloc(sizeof(Node));
    assert(p /*!= NULL*/);
    this -> next = next;
    this -> data = data;

    return p;
}

void List::initList()
{
    this -> ptr = createNode(-1, NULL);
}
void List::cleanupList()
{
    Node *p = this -> ptr;

    while (p )
    {
        Node *tmp = p;
        p = this -> next;
        free(tmp);
    }
}

void List::insertFirstNode(int data)
{
    // Node *p = malloc(sizeof(Node));
    // this -> data = data;
    // this -> next = this -> ptr -> next;
    // this -> ptr -> next = p;
    this -> ptr -> next = createNode(data, this -> ptr -> next);
}
void List::insertNode(int prevData, int data)
{
    Node *ptr = this -> ptr -> next;
    while (ptr )    
    {
        if(ptr -> data == prevData)
        {
            break;
        }
        ptr = ptr -> next;
    }

    if(ptr )        // found!
    {
        // Node *p = malloc(sizeof(Node));
        // this -> data = data;
        // this -> next = ptr -> next;
        // ptr -> next = p;
        ptr -> next = createNode(data, ptr -> next);
    }
    
}
void List::deleteNode(int data)
{
    Node *ptr1 = this -> ptr -> next;
    Node *ptr2 = this -> ptr;

    while (ptr1 )
    {
        if (ptr1 -> data == data)
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

void List::printList(const List *pList)
{
    Node *p = this -> ptr -> next;
    printf("[");
    while (p )
    {
        printf("%d", this -> data);
        // if(this -> next /* != NULL */)
        // {
        //     printf(", ");
        // }
        // else
        // {
        //     printf("]\n");
        // }
        printf( (this -> next /* != NULL */) ? ", " : "]\n");
        
        p = this -> next;

    }
}
