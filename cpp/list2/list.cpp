#include <iostream>
#include <cassert>
#include "list.h"

Node::Node(int data, Node *next)
{
    this -> data = data;
    this -> next = next;
}

Node::~Node()
{

}

List::List()
{
    // this -> ptr = createNode(-1, NULL);
    this -> ptr = new Node(-1, NULL);
    assert(this -> ptr );
}

List::~List()
{
    Node *p = this -> ptr;

    while (p )
    {
        Node *tmp = p;
        p = p -> next;
        delete tmp;
    }
}

void List::insertFirstNode(int data)
{
    // this -> ptr -> next = createNode(data, this -> ptr -> next);
    this -> ptr -> next = new Node(data, this -> ptr -> next);
    assert(this -> ptr -> next );
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
        // ptr -> next = createNode(data, ptr -> next);
        ptr -> next = new Node(data, ptr -> next);
        assert(this -> ptr -> next);
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
        delete ptr1;
    }
}

void List::print()
{
    Node *p = this -> ptr -> next;
    std::cout << "[";
    while (p )
    {
        // printf("%d", p -> data);
        // printf( (p -> next /* != NULL */) ? ", " : "]\n");
        std::cout << p -> data;
        std::cout << ((p -> next) ? ", " : "]\n");
        
        
        p = p -> next;

    }
}