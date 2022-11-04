#pragma once
#include"Node.h"
class Doubly_list
{
public:
	Node* top;
	Doubly_list() :top(0){}
	bool isEmpty();
	void push(Employee v);
	Employee pop();
	void Display_List();
	//bool isFull();
	//int get_Top() const;
};