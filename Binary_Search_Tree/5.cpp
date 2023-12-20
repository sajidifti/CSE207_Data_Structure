// CPP program to find sum of
// all leaf nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

// struct binary tree node
struct Node
{
	int data;
	Node *left, *right;
};

// return new node
Node *newNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void lefttreeleafSum(Node *root, int &sum)
{
	if (!root)
		return;
	else
		root = root->left;
	if (!root->left && !root->right)
		sum += root->data;

	lefttreeleafSum(root->left, sum);
	lefttreeleafSum(root->right, sum);
}

void righttreeleafSum(Node *root, int &sum)
{
	if (!root)
		return;
	else
		root = root->right;

	if (!root->left && !root->right)
		sum += root->data;

	righttreeleafSum(root->right, sum);
	righttreeleafSum(root->left, sum);
}

int main()
{

	Node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right = newNode(3);
	root->right->right = newNode(8);
	root->right->right->left = newNode(6);
	root->right->right->right = newNode(7);

	int sum = 0;
	lefttreeleafSum(root, sum);

	int sum2 = 0;
	righttreeleafSum(root, sum2);

	if(sum > sum2) printf("%d", sum);
	else printf("%d", sum2);

	return 0;
}
