#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *top;

void push(int data)
{

    struct Node *temp;
    temp = new Node();

    if (!temp)
    {
        return;
    }

    temp->data = data;

    temp->link = top;

    top = temp;
}

int isEmpty()
{
    return top == NULL;
}

int peek()
{

    if (!isEmpty())
        return top->data;
    else
        return -1;
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        return;
    }
    else
    {

        temp = top;

        top = top->link;

        temp->link = NULL;

        free(temp);
    }
}

void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        return;
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{

    int a;

    printf("List of Numbers: ");

    scanf("%d", &a);

    while (a >= 0)
    {
        push(a);
        scanf("%d", &a);
    }

    display();

    return 0;
}