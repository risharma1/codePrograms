#include <iostream>
using namespace std;


// A Binary Tree Node 
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node 
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int kthAncestor(Node* root, int k, int node, int &ancestor)
{
	if (!root) return -1;
	if (node == root->data) return 0;
	int left = kthAncestor(root->left, k, node, ancestor);
	if (left != -1)
	{
		if (ancestor == -1 && k == left + 1) ancestor = root->data;
		return left + 1;
	}
	int right = kthAncestor(root->right, k, node, ancestor);
	if (right != -1)
	{
		if (ancestor == -1 && k == right + 1) ancestor = root->data;
		return right + 1;
	}
	return -1;
}

// Driver program to test above functions 
int main()
{
	// Let us create binary tree shown in above diagram 
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 2;
	int node = 5;
	int ancestor = -1;
	// print kth ancestor of given node 
	int result = kthAncestor(root, k, node, ancestor);
	cout << ancestor;
	return 0;
}