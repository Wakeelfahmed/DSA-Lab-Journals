#include "Doubly_list.h"
using namespace std;
#include<iostream>
bool Doubly_list::isEmpty() {
	if (head == 0)
		return true;
	return false;
}
void Doubly_list::insert_beg(Employee value) {
	Node* temp;
	temp = new Node(value);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;
}
void Doubly_list::insert_end(Employee value) {
	Node* s, * temp;
	temp = new Node(value);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	else
	{
		s = head;
		while (s->next != NULL)
			s = s->next;
		s->next = temp;
		temp->prev = s;
	}
}
void Doubly_list::Display_List() {
	Node* p = head;
	cout << "List:\n";
	while (p != NULL)
	{
		cout << "NIC:" << p->data.NIC << "\tName:" 
			<< p->data.EmpName << "\tID:" << p->data.EmpID 
			<< "\tJOD:" << p->data.Joining_Data << endl;
		p = p->next;
	}	cout << endl;
}
//bool Doubly_list::isFull() {}
//int Doubly_list::get_Top() const {}