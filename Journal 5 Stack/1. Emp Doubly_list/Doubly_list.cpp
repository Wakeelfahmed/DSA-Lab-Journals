#include<iostream>
#include "Doubly_list.h"
using namespace std;
Doubly_list::Doubly_list() :head(0) {}
bool Doubly_list::isEmpty() {
	if (head == 0)
		return true;
	return false;
}
void Doubly_list::insert_beg(Employee value) {
	Node* New_Node = new Node(value);
	if (head == NULL)
	{
		head = New_Node;
		return;
	}
	New_Node->next = head;
	head->prev = New_Node;
	head = New_Node;
}
void Doubly_list::insert_end(Employee value) {
	Node* p, * New_Node = new Node(value);
	if (head == NULL)
	{
		head = New_Node;
		return;
	}
	else
	{
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = New_Node;
		New_Node->prev = p;
	}
}
bool Is_Present_in_list(const Doubly_list list, string EmployeeID) {
	Node* p = list.head;
	while (p != NULL)
	{
		if (p->data.get_EmpID() == EmployeeID)
			return true;
		p = p->next;
	}
	return false;
}
void Doubly_list::insert_after(Employee prev_Employee, Employee v) {
	if (isEmpty())
		return;
	if (!Is_Present_in_list(*this, prev_Employee.get_EmpID())) {
		cout << prev_Employee.get_EmpName() << " Does not exist in List\n"; return;
	}
	Node* p = head, * NewNode = new Node(v);
	while (p != NULL)
	{
		if (p->data.get_EmpID() == prev_Employee.get_EmpID())
		{
			NewNode->next = p->next;
			NewNode->prev = p;
			p->next = NewNode;
		}
		p = p->next;
	}
}
void Doubly_list::Display_List() {
	if (isEmpty())
	{
		cout << "list is empty\n"; return;
	}
	int pos = 1;
	Node* p = head;
	cout << "List:\n";
	while (p != NULL)
	{
		cout << pos << ". "; p->data.Display_Employee_Details();
		p = p->next;	pos++;
	}	cout << endl;
}
void Doubly_list::remove(string id) {
	if (isEmpty())
		return;
	Node* p = head;
	if (head->data.get_EmpID() == id) {
		head = p->next;
		delete p;
		cout << "Found & Deleted\n";
		return;
	}
	while (p != NULL)
	{
		if (p->data.get_EmpID() == id) {
			Node* temp = p;
			cout << "Found & Deleted\n";
			p->prev->next = p->next;
			if (p->next != NULL)
				p->next->prev = p->prev;
			delete p;
			return;
		}
		p = p->next;
	}
	cout << "Record does not exist\n";
}
void Doubly_list::update_Salary(long long int newsalary, string employee_id) {
	if (isEmpty())
		return;
	Node* p = head;
	while (p != NULL)
	{
		if (p->data.get_EmpID() == employee_id) {
			p->data.set_Salary(newsalary);
			return;
		}
		p = p->next;
	}
	cout << "Record does not exist\n";
}
void Doubly_list::update_Bonus(long long int new_Bonus, string employee_id) {
	if (isEmpty())
		return;
	Node* p = head;
	while (p != NULL)
	{
		if (p->data.get_EmpID() == employee_id) {
			p->data.set_Bonus(new_Bonus);
			return;
		}
		p = p->next;
	}
	cout << "Record does not exist\n";
}
Node* Doubly_list::get_Node_by_Pos(int i) const {
	Node* p = head;
	int count = 0;
	while (p != NULL)
	{
		count++;
		if (count == i)
			return p;
		p = p->next;
	}
}
void Doubly_list::Swap(int pos_i, int pos_j) {
	int Number_of_Nodes = 0;
	Node* p = head;
	while (p != NULL)
	{
		Number_of_Nodes++;
		p = p->next;
	}
	if (pos_i > Number_of_Nodes || pos_j > Number_of_Nodes) {
		cout << "Node to swap does not exist\n";
		return;
	}
	Employee Temp_Data = get_Node_by_Pos(pos_i)->data;
	get_Node_by_Pos(pos_i)->data = get_Node_by_Pos(pos_j)->data;
	get_Node_by_Pos(pos_j)->data = Temp_Data;
}
void Doubly_list::clear() {
	Node* p = head, * temp;
	while (p != NULL)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	head = NULL;
}
void Doubly_list::reverse(Node* head) {
	Node* p1, * p2;
	p1 = head;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while (p2 != NULL) {
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;  //loop
	}
	head = p1;
}