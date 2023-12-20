void Delete(int n){
    Node* temp1 = head;
    if (n == 1)
    {
        head = temp1 -> next;
        Delete temp1;
        return;
    }

    int i;
    for ( i = 0; i < n-2; i++)
    {
        temp1 = temp1 -> next;
    }

    Node* temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;
    Delete temp2;
    
    
}


//last node detetion if enters value

Node *p;
Node *tmp;
p = start;
while (p -> link != NULL)
{
    if(p -> link -> info == data){
        tmp = p -> link;
        p -> link = tmp -> link;
        Detele tmp;
    }

    p = p -> link;
}


//last node delete

if (head == null || head -> next == null){
    return null;
}
Node temp = head;
while (temp -> next -> next != null)
{
    temp = temp -> next;
}
temp -> next = null;

