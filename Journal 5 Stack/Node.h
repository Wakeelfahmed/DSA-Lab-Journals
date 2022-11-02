#pragma once
class Node
{
public:
	Node* prev;
	int data;
	Node* next;
	Node();
	Node(int Data);
};