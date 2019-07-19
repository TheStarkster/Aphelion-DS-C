#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *tail;
    struct Node *head;
};
struct Node *RootNode;
struct Node *EndP;

void AddToFirst(float data)
{
    if (RootNode == NULL)
    {
        RootNode = (struct Node *)malloc(sizeof(struct Node));
        RootNode->data = data;
        EndP = RootNode;
    }
    else
    {
        printf("Something Went Wrong!");
    }
}
void AddToLast(float data){
    if(EndP != NULL){
        struct Node *link = (struct Node *)malloc(sizeof(struct Node));
        link->data = data;
        link->head = EndP;
        link->tail = NULL;
        EndP->tail = link;
        EndP = link;
    }
}
void PrintList(){

    struct Node *temp = RootNode;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        printf("\n");
        temp = temp->tail;
    }
}
void main()
{
    AddToFirst(23);
    AddToLast(34);
    AddToLast(4);
    AddToLast(66);
    PrintList();
}
