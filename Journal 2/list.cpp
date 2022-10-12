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
	}
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
void list::insert_after(int oldvalue, int newvalue) {
	if (isEmpty())
	{
		cout << "List is Empty"; return;
	}
	Node* p = head;
	while ((p != NULL) && (p->Data != oldvalue)) { p = p->next; }
	if (p == NULL) { cout << "Node not found"; exit(0); }
	Node* q = new Node;
	q->Data = newvalue;
	q->next = p->next;
	p->next = q;
}//Wrong
/*void list::insert_after(int oldvalue, int newvalue) {
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
				p->next = NewNode;
				tail = NewNode;
				//insert_end(newvalue);
			}
			else
			{
				NewNode->next = p->next;
				p->next = NewNode;
				//insert_specfic_Position(position_count, newvalue);
			}
			return;
		}
		p = p->next;
		position_count++;
	}
}*/
void list::delete_Node(int Value_to_delete) {
	if (isEmpty())
	{
		cout << "List is Empty"; return;
	}
	Node* p = head;
	while (p != NULL) {
		//if (p->next == NULL && p->Data != Value_to_delete)
		{
		//	cout << "Node not in the list";
		//	return;
		}
		if(head == tail && Value_to_delete == head->Data) {
			cout << "true";
			delete p;
			head = NULL; tail = NULL;
			return;
		}
		else if (head->Data == Value_to_delete) {
			//cout << "HEAD loop->next->Data:" << (p->next->Data) << endl;
			head = p->next;
			cout << "p->Data " << p->Data;
			delete p;
			return;
		}
		else if (tail->Data == Value_to_delete && p->next->Data == Value_to_delete) {
			//cout << "me";
			delete p->next;
			p->next = NULL;
			tail = p;
			return;
		}
		else if (p->next->Data == Value_to_delete && !(tail->Data == Value_to_delete))
		{
			Node* Temp = p->next->next;
			cout << "p->next->Data " << p->next->Data;
			delete p->next;
			p->next = Temp;
			cout << " \tDeleted p->next->Data " << endl;
			return;
		}
		p = p->next;
		//if (p.next == NULL && p->Data != Value_to_delete)
		{
			//cout << "Node not in the list";
			//return;
		}
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
	return 0; // no record found
}