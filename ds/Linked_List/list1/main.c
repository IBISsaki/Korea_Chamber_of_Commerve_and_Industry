#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int main(void)
{
    Node *ptr;

    ptr = malloc(sizeof(Node));
    ptr -> data = 1;
    ptr -> next = malloc(sizeof(Node));

    ptr -> next -> data = 3;
    ptr -> next -> next = malloc(sizeof(Node));

    ptr -> next -> next -> data = 4;
    ptr -> next -> next -> next = NULL;

    {
        Node *p;
        p = malloc(sizeof(Node));
        p -> data = 2;
        p -> next = ptr -> next;
        ptr -> next = p;
    }

    {
        Node *p;
        p = ptr -> next -> next;
        ptr -> next -> next = p -> next;
        free(p);
    }

    {    
        Node *p;
        p = ptr;
        while(p != NULL)
        {
            printf("%d ", p -> data);
            p = p -> next;
        }
        printf("\n");
    }
    
    {
            {    
        Node *p;
        p = ptr;
        while(p /* != NULL */)
        {
            Node *tmp = p;
            p = p -> next;
            free(tmp);
        }
    }
    }

    return 0;
}