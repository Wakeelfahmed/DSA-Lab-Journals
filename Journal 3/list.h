#pragma once
#include"Node.h"
class list
{
private:
	Student_Node* head;
	Student_Node* tail;
public:
	list();
	Student_Node* get_head() const;
	Student_Node* get_tail() const;
	void insert_beg(Student_Node** NewNode);
	void insert_specfic_Position(int place, Student_Node* student);
	void insert_after(Student_Node* oldvalue, Student_Node* newvalue);
	void insert_end(Student_Node* student);
	void Display_list();
	bool isEmpty();
	int Number_of_Nodes();
};
/*void insert_beg(Student student);
void insert_specfic_Position(int place, Student student);
void insert_after(Student oldvalue, Student newvalue);*/

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


