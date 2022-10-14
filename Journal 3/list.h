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
	void insert_beg(Student student);
	void insert_specfic_Position(int place, Student student);
	void insert_after(Student old,Student student);
	void insert_end(Student student);
	void Display_list();
	bool isEmpty();
	int Number_of_Nodes();
	void delete_Student(Student Value_to_delete);
};


