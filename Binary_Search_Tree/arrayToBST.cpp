#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *Insert(struct node *root, int data)
{

    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (root->data >= data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

void printSiblings(struct node *root)
{
    if (root != NULL)
    {
        printSiblings(root->left);
        if (root->left != NULL && root->right != NULL)
        {
            printf("%d and %d are Siblings\n", root->left->data, root->right->data);
        }
        printSiblings(root->right);
    }
}

int main()
{
    int n;
    struct node *root = NULL;

    printf("Input Array Size: ");
    scanf("%d", &n);
    int array[n];

    printf("Input Array Elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        root = Insert(root, array[i]);
    }

    printSiblings(root);

    return 0;
}