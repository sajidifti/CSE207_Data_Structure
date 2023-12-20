sort(){
    node *i, *j;
    int temp;

    for ( i = start; i ->  next!=NULL; i = i -> next)
    {
        for ( j = i->next; j!=null; < j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i -> data;
                i -> data = j -> data;
                j->data = temp;
            }
            
        }
        
    }
    
}