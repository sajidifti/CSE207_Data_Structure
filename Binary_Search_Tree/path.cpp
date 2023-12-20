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

void InOrder(struct node* root)
{
    if (root != NULL) {
        InOrder(root->left);
        printf("%d ,", root->data);
        InOrder(root->right);
    }
}

void PrintPaths(struct node *root, int *array, int n)
{
    array[n] = root->data;
    n++;

    if (root == NULL)
    {
        printf("Empty Tree\n");
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {

        for (int i = 0; i < n - 1; i++)
        {
            printf("%d , ", array[i]);
        }

        printf("%d\n", array[n - 1]);
    }

    if (root->left != NULL)
    {

        PrintPaths(root->left, array, n);
    }

    if (root->right != NULL)
    {

        PrintPaths(root->right, array, n);
    }
}

int main()
{
    int array[1000], option;

    node *root = NULL;

    while (1)
    {
        printf("\n1. Insert Data to The BST\n2. Print InOrder and Paths\n3. Exit\nEnter Your Option: ");
        scanf("%d", &option);

        if (option == 1)
        {
            int data;
            printf("\nEnter Data: ");
            scanf("%d", &data);
            root = Insert(root, data);
        }
        else if (option == 2)
        {
            printf("\nInOrder Traversal\n");
            InOrder(root);
            printf("\nRoot-to-leaf Paths\n");
            PrintPaths(root, array, 0);
        }
        else if (option == 3)
            break;
        else
            printf("\nInvalid Option. Try Again.\n");
    }
}
