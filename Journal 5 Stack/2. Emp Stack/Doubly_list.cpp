#include "Doubly_list.h"
using namespace std;
#include<iostream>
bool Doubly_list::isEmpty() {
	if (top == 0)
		return true;
	return false;
}
Employee Doubly_list::pop() {
	Node* p = top;
	Employee Temp;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	Temp = p->next->data;
	cout <<"Last Node"<< Temp.EmpName << endl;
	delete p->next;
	p->next = NULL;
	return Temp;
}
void Doubly_list::push(Employee value) {
	Node* s, * temp;
	temp = new Node(value);
	if (top == NULL)
	{
		top = temp;
		return;
	}
	else
	{
		s = top;
		while (s->next != NULL)
			s = s->next;
		s->next = temp;
		temp->prev = s;
	}
}
void Doubly_list::Display_List() {
	Node* p = top;
	cout << "List:\n";
	while (p != NULL)
	{
		p->data.Display_Employee_Details();
		p = p->next;
	}	cout << endl;
}