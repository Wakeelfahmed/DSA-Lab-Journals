#include<iostream>
#include<Bits.h>
using namespace std;
class node {
	char data;
public:
	node() : left(NULL), right(NULL) {}
	node(char c) : data(c), left(NULL), right(NULL) {}
	node* left;
	node* right;
	node* next = NULL;
	friend class Stack;
	friend class expression_tree;
};
class Stack {
	node* head = NULL;
public:
	void push(node*);
	node* pop();
	friend class expression_tree;
};
class expression_tree {
public:
	void inorder(node* x)
	{
		// cout<<"Tree in InOrder Traversal is: "<<endl;
		if (x == NULL)
			return;
		else {
			inorder(x->left);
			cout << x->data << " ";
			inorder(x->right);
		}
	}
	void preorder(node* ptr)
	{
		if (ptr == NULL)
		{
			return;
		}
		else
		{
			cout << "value is: " << ptr->data << endl;
			preorder(ptr->left);
			preorder(ptr->right);
		}
	}
	void postorder(node* ptr)
	{
		if (ptr == NULL)
		{
			return;
		}
		else
		{
			postorder(ptr->left);
			postorder(ptr->right);
			cout << "value is: " << ptr->data << endl;
		}
	}
};
void Stack::push(node* x)
{
	if (head == NULL) {
		head = x;
	}
	// We are inserting here nodes at the top of the stack [following LIFO principle]
	else {
		x->next = head;
		head = x;
	}
}
node* Stack::pop()
{
	node* p = head;
	head = head->next;
	return p;
}
int main()
{
	string s;
	cout << "Enter Postfix expression:";
	cin >> s;
	Stack e;
	expression_tree Expression_Tree;
	node* x, * y, * z = NULL;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		// if read character is operator then popping two
		// other elements from stack and making a binary
		// tree
		if (s[i] == '+' || s[i] == '-' || s[i] == '*'
			|| s[i] == '/' || s[i] == '^') {
			z = new node(s[i]);
			x = e.pop();
			y = e.pop();
			z->left = y;
			z->right = x;
			e.push(z);
		}
		else {
			z = new node(s[i]);
			e.push(z);
		}
	}
	cout << "The Inorder Traversal of Expression Tree: ";
	Expression_Tree.inorder(z);
}
unsigned int getLeafCount(struct node* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return getLeafCount(node->left) +
		getLeafCount(node->right);
}
int countNonleaf(struct Node* root)
{
	// Base cases.
	if (root == NULL || (root->left == NULL &&
		root->right == NULL))
		return 0;

	// If root is Not NULL and its one of its
	// child is also not NULL
	return 1 + countNonleaf(root->left) +
		countNonleaf(root->right);
}
void insert_BT(int value)
{
	node* p = new node;
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	if (root == NULL)
	{
		root = p;
	}
	else
	{
		node* ptr = root;
		node* parent;
		while (ptr != NULL)
		{
			parent = ptr;
			if (value >= ptr->data)
			{
				ptr = ptr->right;
			}
			else if (value < ptr->data)
			{
				ptr = ptr->left;
			}
		}
		if (value >= parent->data)
		{
			parent->right = p;
		}
		else
		{
			parent->left = p;
		}
	}
}
int countnodes(struct node* root)
{
	if (root != NULL)
	{
		countnodes(root->left);
		count++;
		countnodes(root->right);
	}
	return count;
}