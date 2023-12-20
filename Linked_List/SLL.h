#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class SLL
{

public:
    Node *head = NULL;
    //1
    void add(int item)
    {
        Node *temp = new Node(item);
        temp->data = item;
        temp->next = NULL;

        Node *nextPointer = head;

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

    //2
    void addbegin(int item)
    {
        Node *temp = new Node(item);
        temp->data = item;
        temp->next = head;
        head = temp;
    }

    //3
    void addanypos(int pos, int item)
    {
        Node *temp1 = new Node(item);
        temp1->data = item;
        temp1->next = NULL;
        if (pos == 1)
        {
            temp1->next = head;
            head = temp1;
            return;
        }

        Node *temp2 = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    //4
    bool contains(int item)
    {
        Node *p;
        Node *tmp;
        p = head;
        while (p->next != NULL)
        {
            if (p->next->data == item)
            {
                return true;
            }

            p = p->next;
        }

        return false;
    }

    //5
    int size()
    {
        Node *p;
        Node *tmp;
        p = head;
        int count = 0;
        while (p->next != NULL)
        {
            count++;
            p = p->next;
        }

        return count;
    }

    //6
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //7
    int get(int pos)
    {
        Node *temp1 = head;

        if (pos == 1)
        {
            return (temp1->data);
        }

        Node *temp2 = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp2 = temp2->next;
        }

        return (temp2->data);
    }

    //8
    int indexOf(int item)
    {
        Node *current = head;
        int count = 1;

        if (head == NULL)
        {
            return -1;
        }
        else
        {
            while (current != NULL)
            {
                if (current->data == item)
                {
                    return count;
                }
                count++;
                current = current->next;
            }
        }

        return 0;
    }

    //9
    void removefirst()
    {
        Node *temp1 = head;
        head = temp1->next;
        delete temp1;
    }

    //10
    void removelast()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Linked List Is Aalready Empty";
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }

    //11
    void remove(int pos)
    {
        Node *temp1 = head;
        if (pos == 1)
        {
            head = temp1->next;
            delete temp1;
            return;
        }

        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }

        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }

    //12
    void reverse()
    {
        Node *current, *prev, *next;
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    //13
    void sort()
    {
        Node *i, *j;
        int temp;

        for (i = head; i->next != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->data > j->data)
                {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    //14
    void display()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            cout << "List is: ";
            while (temp != NULL)
            {
                cout << temp->data;
                cout << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};
