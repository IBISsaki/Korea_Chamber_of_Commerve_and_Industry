#ifndef LIST_H
#define LIST_H

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next);
    ~Node();
};


class List 
{
private:
    Node *ptr;
public:
    List();
    ~List();

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);

    void print();
};

#endif