#include"list.h"
#include"Node.h"
#include<iostream>
using namespace std;
list::list() : head(NULL), tail(NULL) {}
Node* list::get_head() const { return head; }
Node* list::get_tail() const { return tail; }
bool list::isEmpty() {
	if (head == NULL)
		return true;
	return false;
}
void list::insert_beg(int v) {
	Node* p = new Node;
	p->Data = v;
	if (isEmpty())
		tail = p;
	else
		p->next = head;
	head = p;
}
void list::insert_specfic_Position(int Position, int newvalue) {
	int position_count = 1;
	if (Position > Number_of_Nodes()) {
		cout << "List has less nodes than the place, Node CAN't be inserted!!\n";
		return;
	}//
	Node* NewNode = new Node;
	NewNode->Data = newvalue;
	Node* p = head;
	while (p != NULL)
	{
		if (Position == 1) {
			insert_beg(newvalue);
			return;
		}
		else if (Position == Number_of_Nodes()) {
			insert_end(newvalue);
			return;
		}
		else if (position_count == Position - 1 && Position != 0) {
			NewNode->next = p->next;
			p->next = NewNode;
			return;
		}
		p = p->next;		//move to next node
		position_count++;
	}
}
void list::inser_after(int oldvalue, int newvalue) {
	if (isEmpty())
	{
		cout << "List is empty";
		return;
	}
	Node* p = head;
	int position_count = 1;
	while (p != NULL)
	{
		if (p->Data == oldvalue)
		{
			Node* NewNode = new Node;
			NewNode->Data = newvalue;
			if (position_count == Number_of_Nodes()) {
				insert_end(newvalue);
			}
		}
		p = p->next;
		position_count++;
	}
}
void list::insert_end(int value) {
	Node* p = new Node;
	p->Data = value;
	if (isEmpty())
	{
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}
void list::Display_list() {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = head;
	cout << "List: \t";
	while (p != NULL)
	{
		cout << p->Data << "\t";
		p = p->next;
	}
	cout << endl;
}
int list::Number_of_Nodes() {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 0;
	Node* p = head;
	while (p != NULL)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}
int Search_in_List(int Value_to_search, list list) {
	Node* p = list.get_head();
	int Position_counter = 1;
	while (p != NULL)
	{
		if (p->Data == Value_to_search)
			return Position_counter;
		p = p->next;
		Position_counter++;
	}
	return 0;
}
/*void list::inser_after(int value, int newvalue) {
	Node* r = new Node;
	Node* q;

	Node* p = head;
	while (p != NULL && (p->Data != value))
	{
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "Node not found";
		return;
	}
}*/