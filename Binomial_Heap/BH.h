#include <iostream>
#include <cstdlib>
#include "node.h"
using namespace std;

/*
 * Class Declaration
 */
class BinomialHeap
{
private:
    node *H; //head
    node *Hr; //
    int count;

public:
    node *Initializeheap();
    int Binomial_link(node *, node *);
    node *Create_node(int);
    node *Union(node *, node *);
    node *Insert(node *, node *);
    node *Merge(node *, node *);
    node *Extract_Min(node *);
    int Revert_list(node *);
    int Display(node *);
    node *Search(node *, int);
    int Decrease_key(node *, int, int);
    int Delete(node *, int);
    
    BinomialHeap()
    {
        H = Initializeheap();
        Hr = Initializeheap();
        int count = 1;
    }
};

/*
 * Initialize Heap
 */
node *BinomialHeap::Initializeheap()
{
    node *np;
    np = NULL;
    return np;
}
/*
 * Linking nodes in Binomial Heap
 */
int BinomialHeap::Binomial_link(node *y, node *z)
{
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}
/*
 * Create Nodes in Binomial Heap
 */
node *BinomialHeap::Create_node(int k) //k is the value inserted by user
{
    node *p = new node;
    p->n = k;
    return p;
}
/*
 * Insert Nodes in Binomial Heap
 */
node *BinomialHeap::Insert(node *H, node *x)
{
    node *H1 = Initializeheap();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = Union(H, H1);
    return H;
}

/*
 * Union Nodes in Binomial Heap
 */
node *BinomialHeap::Union(node *H1, node *H2)
{
    node *H = Initializeheap();
    H = Merge(H1, H2);
    if (H == NULL)
        return H;
    node *prev_x;
    node *next_x;
    node *x;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL)
    {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree))
        {
            prev_x = x;
            x = next_x;
        }
        else
        {
            if (x->n <= next_x->n)
            {
                x->sibling = next_x->sibling;
                Binomial_link(next_x, x);
            }
            else
            {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                Binomial_link(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}
/*
 * Merge Nodes in Binomial Heap
 */
node *BinomialHeap::Merge(node *H1, node *H2)
{
    node *H = Initializeheap();
    node *y;
    node *z;
    node *a;
    node *b;
    y = H1;
    z = H2;
    if (y != NULL)
    {
        if (z != NULL)
        {
            if (y->degree <= z->degree)
                H = y;
            else if (y->degree > z->degree)
                H = z;
        }
        else
            H = y;
    }
    else
        H = z;
    while (y != NULL && z != NULL)
    {
        if (y->degree < z->degree)
        {
            y = y->sibling;
        }
        else if (y->degree == z->degree)
        {
            a = y->sibling;
            y->sibling = z;
            y = a;
        }
        else
        {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }
    return H;
}
/*
 * Display Binomial Heap
 */
int BinomialHeap::Display(node *H)
{
    if (H == NULL)
    {
        cout << "The Heap is empty" << endl;
        return 0;
    }
    cout << "The root nodes are: " << endl;
    node *p;
    p = H;
    while (p != NULL)
    {
        cout << p->n;
        if (p->sibling != NULL)
            cout << "-->";
        p = p->sibling;
    }
    cout << endl;
}
/*
 * Extract Minimum
 */
node *BinomialHeap::Extract_Min(node *H1)
{
    Hr = NULL;
    node *t = NULL;
    node *x = H1;
    if (x == NULL)
    {
        cout << "Nothing to Extract" << endl;
        return x;
    }
    int min = x->n;
    node *p = x;
    while (p->sibling != NULL)
    {
        if ((p->sibling)->n < min)
        {
            min = (p->sibling)->n;
            t = p;
            x = p->sibling;
        }
        p = p->sibling;
    }
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;
    if (x->child != NULL)
    {
        Revert_list(x->child);
        (x->child)->sibling = NULL;
    }
    H = Union(H1, Hr);
    return x;
}
/*
 * Reverse List
 */
int BinomialHeap::Revert_list(node *y)
{
    if (y->sibling != NULL)
    {
        Revert_list(y->sibling);
        (y->sibling)->sibling = y;
    }
    else
    {
        Hr = y;
    }
}

/*
 * Search Nodes in Binomial Heap
 */
node *BinomialHeap::Search(node *H, int k)
{
    node *x = H;
    node *p = NULL;
    if (x->n == k)
    {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL)
        p = Search(x->child, k);
    if (x->sibling != NULL && p == NULL)
        p = Search(x->sibling, k);
    return p;
}
/*
 * Decrease key of a node
 */
int BinomialHeap::Decrease_key(node *H, int i, int k)
{
    int temp;
    node *p;
    node *y;
    node *z;
    p = Search(H, i);
    if (p == NULL)
    {
        cout << "Invalid choice of key" << endl;
        return 0;
    }
    if (k > p->n)
    {
        cout << "Error!! New key is greater than current key" << endl;
        return 0;
    }
    p->n = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->n < z->n)
    {
        temp = y->n;
        y->n = z->n;
        z->n = temp;
        y = z;
        z = z->parent;
    }
    cout << "Key reduced successfully" << endl;
}
/*
 * Delete Nodes in Binomial Heap
 */
int BinomialHeap::Delete(node *H, int k)
{
    node *np;
    if (H == NULL)
    {
        cout << "\nHEAP EMPTY!!!!!";
        return 0;
    }
    Decrease_key(H, k, -1000);
    np = Extract_Min(H);
    if (np != NULL)
        cout << "Node Deleted Successfully" << endl;
}