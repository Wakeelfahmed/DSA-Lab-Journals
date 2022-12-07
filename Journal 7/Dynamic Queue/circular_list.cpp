#include"circular_list.h"
#include<iostream>
using namespace std;
circular_list::circular_list() : head(NULL) { }
Node* circular_list::get_head() const { return head; }
bool circular_list::isEmpty() const {
	if (head == NULL)
		return true;
	return false;
}
void circular_list::insert_beg(char v) {
	Node* NewNode = new Node(v);
	if (isEmpty()) {
		head = NewNode;
		NewNode->next = head;
	}
	else {
		NewNode->next = head;
		Node* p = head;
		while (p->next != head)
			p = p->next;
		head = NewNode;
		p->next = head;  //last Node point to head
	}
}
void circular_list::insert_end(char value) {
	Node* NewNode = new Node(value);
	if (isEmpty()) {
		head = NewNode;
		NewNode->next = head;
	}
	else {
		Node* p = head;
		do
		{
			p = p->next;
		} while (p->next != head);
		p->next = NewNode;
		NewNode->next = head;
		return;
	}
}
void circular_list::Display_list() const {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = head;
	cout << "List: \t";
	do
	{
		cout << p->Data << "\t";
		p = p->next;
	} while (p != head);
	cout << endl;
}
void circular_list::delete_Node(char Value_to_delete) {
	if (isEmpty()) {
		cout << "List is Empty\n"; return;
	}
	//else if (!Search_in_List(Value_to_delete, *this)) {
	//	cout << "Not found in list\n"; return;
	//}
	Node* p = head;
	Node* Temp;
	if (Value_to_delete == head->Data) {
		Temp = p;
		if (head->next == head) {
			delete Temp; head = NULL; return;
		}
		else
		{
			do
			{
				p = p->next;
			} while (p->next != head);
			p->next = head->next;
			head = head->next;
			delete Temp;
			return;
		}
	}
	else
	{
		p = head;
		do
		{
			if (p->next->Data == Value_to_delete)
			{
				Temp = p->next;
				p->next = p->next->next;
				delete Temp;
				return;
			}
			p = p->next;
		} while (p->next != head);
	}
}
int circular_list::Number_of_Nodes() const {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 1;
	Node* p = head;
	while (p != head)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}
Node* circular_list::get_Last_Node() const {
	Node* p = head;
	do {
		p = p->next;
	} while (p->next != head);
	return p;
}
