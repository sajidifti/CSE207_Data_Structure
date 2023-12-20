#include <stdio.h>
#include <stdlib.h>

int h = 0;
int last = -1;

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

void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ,", root->data);
        InOrder(root->right);
    }
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

struct node *FindMinAddress(struct node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *Delete(struct node *root, int data)
{
    if (root == NULL)
        return root;

    else if (data < root->data)
        root->left = Delete(root->left, data);

    else if (data > root->data)
        root->right = Delete(root->right, data);

    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct node *tmp = FindMinAddress(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    return root;
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

    last = array[n - 1];

    if (root->left == NULL && root->right == NULL && n == h)
    {

        for (int i = 0; i < n - 1; i++)
        {
            printf("%d , ", array[i]);
        }
        printf("%d\n", last);
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
        printf("\n1. Insert Data to The BST\n2. Print InOrder and Path\n3. Exit\nEnter Your Option: ");
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
            printf("\nLongest Root-to-leaf Path\n");
            h = height(root);
            PrintPaths(root, array, 0);
            if (last != -1)
            {
                root = Delete(root, last);
                printf("\nInOrder Traversal After Deletion\n");
                InOrder(root);
            }
        }
        else if (option == 3)
            break;
        else
            printf("\nInvalid Option. Try Again.\n");
    }
}
