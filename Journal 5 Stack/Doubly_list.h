#pragma once
#include"Node.h"
class Doubly_list
{
public:
	Node* head;
	Doubly_list() :head(0){}
	bool isEmpty();
	void insert_beg(int v);
	void insert_end(int v);
	void Display_List();
	//bool isFull();
	//int get_Top() const;
};