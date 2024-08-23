#ifndef LIST_H
#define LIST_H

struct Node
{
    int data;
    struct node *next;
};


struct List 
{
    Node *ptr;

void initList();
void cleanupList();

void insertFirstNode(int data);
void insertNode(int prevData, int data);
void deleteNode(int data);

void printList(const List *pList);
};



#endif
