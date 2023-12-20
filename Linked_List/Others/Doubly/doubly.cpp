#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head;

Node *GetNewNode(int x)
{
    Node *newNode = new Node[sizeof(Node)];
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print()
{
    Node *temp = head;
    cout << "Forward: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void ReversePrint()
{
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "Reverse: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}