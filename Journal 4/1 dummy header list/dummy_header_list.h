#pragma once
#include"Node.h"
class dummy_header_list
{
private:
	Node* head;
public:
	dummy_header_list();
	Node* get_head() const;
	int get_Node_Data(int Node_of_list);
	void insert_beg(int v);
	void insert_end(int value);
	void insert_specfic_Position(int place, int value);
	void insert_after(int oldvalue, int newvalue);
	void delete_Node(int Value_to_delete);
	void Display_list() const;
	bool isEmpty() const;
	int Number_of_Nodes()const ;
	~dummy_header_list();
	dummy_header_list(const dummy_header_list& i); //Copy contructor
	dummy_header_list& operator=(const dummy_header_list& t); //Copy Assignment
};