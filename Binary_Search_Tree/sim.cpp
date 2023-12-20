#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;

typedef struct node *NodeB;

void push(int data)
{
    NodeB newNode = (NodeB)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    int data = top->data;
    top = top->next;
    return data;
}

int main()
{
    int data;

    printf("Enter number: ");
    while (1)
    {

        scanf("%d", &data);
        if (data > 0)
            push(data);
        else
        {
            if (top == NULL)
            {
                printf("Error!!\n");
            }

            while (top != NULL)
            {
                printf("%d ", pop());
            }
        }
    }

    return 0;
}