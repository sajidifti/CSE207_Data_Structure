//inserting a node at the begining

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

void Insert(int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;

    // temp -> next = NULL;
    /* if (head != NULL)
    {
        temp -> next = head;
    }
    head = temp; */
    
};

void Print(){
    Node* temp = head;
    cout << "List is: ";
    while (temp != NULL)
    {
        cout << temp -> data;
        cout << " ";
        temp = temp -> next;
    }
    cout << endl;
    
};

int main() {
    head = NULL;
    cout << "How many numbers?\n";
    int n, i, x;
    cin >> n;

    for ( i = 0; i < n; i++)
    {
        cout << "Enter the number: ";
        cin >> x;
        Insert(x);
        Print();
    }
    Print();
    
}


//insert at end

inser(node *head, int data){
    node *temp = new node;
    temp -> data =data;
    temp -> next = null;

    node *ptr =head;

    if(head == null){
        head = temp;
        return head;
    }

    while(ptr -> next != null){
        ptr = ptr -> next;
    }

    ptr -> next = temp;

    return head;
}
