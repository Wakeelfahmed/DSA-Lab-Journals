#pragma once
#include"Node.h"
class list
{
private:
	Node* head;
	Node* tail;
public:
	list();
	Node* get_head() const;
	Node* get_tail() const;
	void insert_beg(int v);
	void insert_end(int value);
	void insert_specfic_Position(int place, int value);
	void insert_after(int oldvalue, int newvalue);
	void delete_Node(int Value_to_delete);
	void Display_list();
	bool isEmpty();
	int Number_of_Nodes();
};

