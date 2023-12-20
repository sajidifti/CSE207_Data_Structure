#include <bits/stdc++.h>
#include "node.h"
using namespace std;

template <typename T>
class stack
{
    Node top;

public:
    void push(T data)
    {
        Node *temp = new Node();

        if (!temp)
        {
            cout << "\nHeap Overflow";
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

    T top()
    {
        if (!isEmpty())
            return top->data;
        else
            return;
    }

    void pop()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
            return;
        }
        else
        {
            temp = top;
            top = top->link;
            temp->link = NULL;
            delete[] temp;
        }
    }

    void display()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow";
            return;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << "-> ";
                temp = temp->link;
            }
        }
    }

    void copy(stack sCopy)
    {
        stack temp;

        while (!isEmpty())
        {
            temp.push(top());
            pop();
        }

        while (!temp.isEmpty())
        {
            push(temp.top());
            sCopy.push(temp.top());
            temp.pop();
        }
    }
};