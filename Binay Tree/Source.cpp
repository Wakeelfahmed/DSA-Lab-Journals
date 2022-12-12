#include<iostream>
using namespace std;
template <typename T>
class Node
{
private:
	T Data;
	Node* left, * right;
public:
	Node() : Data(0), left(0), right(0) {}
};
template <typename T1>
class BinaryTree
{
public:
	Node<T1>* root; // pointer to root node
	BinaryTree();
	Node<T1>* insert(<T1>);
	Node<T1>* search(<T1>); // specific to type of tree
	void delete_node(<T1>); // specific to type of tree
	void traverse(); //pre, in, post order
};

int main() {

}