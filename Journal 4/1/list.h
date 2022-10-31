#pragma once
#include"Node.h"
class dummpy_header_list
{
private:
	Node* head;
public:
	dummpy_header_list();
	Node* get_head() const;
	void insert_beg(int v);
	void insert_end(int value);
	void insert_specfic_Position(int place, int value);
	void insert_after(int oldvalue, int newvalue);
	void delete_Node(int Value_to_delete);
	void Display_list() const;
	bool isEmpty() const;
	int Number_of_Nodes()const ;
	~dummpy_header_list();
	//dummpy_header_list(const& i);
};