void Reverse(){
    Node *current, *prev, *next;
    current =head;
    prev =NULL;
    while(current != NULL){
        next = current -> next;
        current -> prev;
        prev = current;
        current = next;
    }
}