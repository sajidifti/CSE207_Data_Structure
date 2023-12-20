#include <stdio.h>

struct node
{
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

struct node *search(int data)
{
   struct node *current = root;
   printf("Visiting elements: ");

   while (current->data != data)
   {

      if (current != NULL)
      {
         printf("%d ", current->data);

         //go to left tree
         if (current->data > data)
         {
            current = current->leftChild;
         } //else go to right tree
         else
         {
            current = current->rightChild;
         }

         //not found
         if (current == NULL)
         {
            return NULL;
         }
      }
   }
   return current;
}

void insert(int data)
{
   struct node *tempNode = (struct node *)malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if (root == NULL)
   {
      root = tempNode;
   }
   else
   {
      current = root;
      parent = NULL;

      while (1)
      {
         parent = current;

         //go to left of the tree
         if (data < parent->data)
         {
            current = current->leftChild;
            //insert to the left

            if (current == NULL)
            {
               parent->leftChild = tempNode;
               return;
            }
         } //go to right of the tree
         else
         {
            current = current->rightChild;

            //insert to the right
            if (current == NULL)
            {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}

void deleteNode(struct node *root, int data)
{

   if (root == NULL)
      root = temp;

   if (data < root->data)
   {
      root->leftChild;
      deleteNode(root->leftChild, data);
   }

   else if (data > root->data)
   {
      root->rightChild;
      deleteNode(root->rightChild, data);
   }
   else
   {
      if (root->leftChild == NULL)
      {
         struct node *temp = root->rightChild;
         free(root);
         return temp;
      }
      else if (root->rightChild == NULL)
      {
         struct node *temp = root->leftChild;
         free(root);
         return temp;
      }

      struct node *temp = minValueNode(root->rightChild);

      root->data = temp->data;

      root->rightChild;
      deleteNode(root->rightChild, temp->data);
   }
   return root;
}

void inOrder(struct node *root)
{
   // Base case
   if (root == NULL)
   {
      return;
   }
   // Travel the left sub-tree first.
   inOrder(root->leftChild);
   // Print the current node value
   printf("%d ", root->data);
   // Travel the right sub-tree next.
   inOrder(root->rightChild);
}

void preOrder(struct node *root)
{
   if (root == NULL)
   {
      return;
   }
   // Print the current node value
   printf("%d ", root->data);
   // Travel the left sub-tree first.
   preOrder(root->leftChild);
   // Travel the right sub-tree next.
   preOrder(root->rightChild);
}

void postOrder(struct node *root)
{
   if (root == NULL)
   {
      return;
   }
   // Travel the left sub-tree first.
   postOrder(root->leftChild);
   // Travel the right sub-tree next.
   postOrder(root->rightChild);
   // Print the current node value
   printf("%d ", root->data);
}

int main()
{
   struct node *newNode = //use malloc

   newNode->search(input data);//take input
}