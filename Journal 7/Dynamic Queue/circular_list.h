#pragma once
#include"Node.h"
class circular_list
{
private:
	Node* head;
public:
	circular_list();
	Node* get_head() const;
	void insert_beg(char v);
	void insert_end(char value);
	void delete_Node(char Value_to_delete);
	void Display_list() const;
	bool isEmpty() const;
	int Number_of_Nodes()const;
	Node* get_Last_Node() const;
};