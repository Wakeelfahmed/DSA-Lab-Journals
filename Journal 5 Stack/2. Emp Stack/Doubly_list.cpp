#include "Doubly_list.h"
using namespace std;
#include<iostream>
bool Doubly_list::isEmpty() {
	if (top == 0)
		return true;
	return false;
}
void Doubly_list::push(Employee value) {
	Node* p, * New_Node = new Node(value);
	if (top == NULL)
	{
		top = New_Node;
		return;
	}
	else
	{
		p = top;
		while (p->next != NULL)
			p = p->next;
		p->next = New_Node;
		New_Node->prev = p;
	}
}
Employee Doubly_list::pop() {
	Node* p = top;
	Employee Temp;
	while (p->next->next != NULL)
		p = p->next;
	Temp = p->next->data;
	cout << "Last Node" << Temp.EmpName << endl;
	delete p->next;
	p->next = NULL;
	return Temp;
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