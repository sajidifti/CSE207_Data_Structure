#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void add(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = NULL;

    struct Node *nextPointer = head;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    while (nextPointer->next != NULL)
    {
        nextPointer = nextPointer->next;
    }

    nextPointer->next = temp;
}

int size()
{
    struct Node *p;
    struct Node *tmp;
    p = head;
    int count = 0;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }

    return count + 1;
}

void remove(int pos)
{
    struct Node *temp1 = head;
    if (pos == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }

    int i;
    for (i = 1; i < pos - 1; i++)
    {
        temp1 = temp1->next;
    }

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next->prev = temp2->prev;
    free(temp2);
}

void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("List is: ");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            printf("\t");
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int option;

        printf("1. Add\n2. Display List\n3. Display Modified List\n4. Exit\n");
        printf("\nChoose Option: ");
        scanf("%d", &option);

        if (option == 1)
        {
            int data;
            printf("Enter Data: ");
            scanf("%d", &data);
            add(data);
        }
        else if (option == 2)
        {
            printf("\nSize = %d\n", size());
            display();
        }

        else if (option == 3)
        {
            int s = size();

            if (s % 2 == 0)
            {
                int a = s / 2;
                remove(a);
                remove(a);
                display();
            }
            else
            {
                int c = (s / 2) + 1;
                remove(c);
                display();
            }
        }
        else if (option == 4)
            break;
        else
            printf("\nInvalid Input. Try Again.\n");
    }

    return 0;
}
