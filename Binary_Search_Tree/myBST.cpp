#include <iostream>
#include <queue>
using namespace std;

struct BSTnode
{
    int data;
    BSTnode *left;
    BSTnode *right;
};

BSTnode *GetNewNode(int data)
{
    BSTnode *newNode = new BSTnode();
    newNode->data = data;
    newNode->left = newNode;
    return newNode;
}

BSTnode *Insert(BSTnode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }

    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(BSTnode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int FindMin(BSTnode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }

    return FindMin(root->left);
}

int FindMax(BSTnode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }

    return FindMin(root->right);
}

int FindHeight(BSTnode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_height = FindHeight(root->left);
        int right_height = FindHeight(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void LevelOrder(BSTnode *root)
{
    if (root == NULL)
        return;
    queue<BSTnode *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        BSTnode *current = Q.front();
        cout << current->data << "\t";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}

void PreOrder(BSTnode *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\t";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BSTnode *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << "\t";
    InOrder(root->right);
}

void PostOrder(BSTnode *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << "\t";
}

bool IsSubTreeLesser(BSTnode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value && IsSubTreeLesser(root->left, value) && IsSubTreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool IsSubTreeGreater(BSTnode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data >= value && IsSubTreeGreater(root->left, value) && IsSubTreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool IsBST(BSTnode *root)
{
    if (root == NULL)
        return NULL;

    if (IsSubTreeLesser(root->left, root->data) && IsSubTreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right))
        return true;
    else
        return false;
}

BSTnode *FindMinAddress(BSTnode *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

BSTnode *Delete(BSTnode *root, int data)
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
            BSTnode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            BSTnode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            BSTnode *tmp = FindMinAddress(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    return root;
}

BSTnode *Find(BSTnode *root, int data)
{
    if (root == NULL || data == root->data)
    {
        return (root);
    }
    if (data < root->data)
    {
        return Find(root->left, data);
    }
    else
    {
        return Find(root->right, data);
    }
}

BSTnode *GetSuccessor(BSTnode *root, int data)
{
    BSTnode *current = Find(root, data);
    if (current == NULL)
        return NULL;
    if (current->right != NULL)
    {
        return FindMinAddress(current->right);
    }
    else
    {
        BSTnode *successor = NULL;
        BSTnode *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main()
{
    BSTnode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 20);
    int a = FindMax(root);
}