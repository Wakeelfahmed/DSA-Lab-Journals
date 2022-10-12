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
	void insert_after(Student oldvalue, Student newvalue);
	void insert_end(Student student);
	void Display_list();
	bool isEmpty();
	int Number_of_Nodes();
};
/*void Find_Student(list list, Student s1) {
	Node* p = list.get_head();
	while (p != NULL)
	{
		if (p->Student_Data == s1) {
			cout << "found";
			return;
		}
		p = p->next;
	}
}*/


