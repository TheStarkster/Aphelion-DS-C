#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *next;
};
struct List
{
    struct Node *RootNode;
    struct Node *EndPointer;
};
void append(struct Node **NodePointer, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->val = data;
    if (*NodePointer == NULL)
    {
        struct List *container = (struct List *)malloc(sizeof(struct List));
        container->RootNode = temp;
        container->EndPointer = temp;
        *NodePointer = &container->RootNode;
    }
    else
    {   
        int *inc = *NodePointer;
        struct Node **TempEndPointer = inc+2;
        (*TempEndPointer)->next = temp;
        *TempEndPointer = temp;  
    }
}
void printlist(struct Node **Pointer)
{
    while ((*Pointer) != NULL)
    {
        printf("%d", (*Pointer)->val);
        printf("%s", "\n");
        (*Pointer) = (*Pointer)->next;
    }
}
void main()
{
    struct Node *FirstNode = NULL;
    append(&FirstNode, 20);
    append(&FirstNode, 30);
    append(&FirstNode, 40);
    append(&FirstNode, 50);
    
    printlist(FirstNode);
}