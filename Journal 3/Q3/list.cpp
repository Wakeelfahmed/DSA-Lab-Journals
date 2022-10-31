#include"list.h"
#include<iostream>
using namespace std;
list::list() : head(NULL), tail(NULL) {}
Node* list::get_head() const { return head; }
Node* list::get_tail() const { return tail; }
bool list::isEmpty() const {
	if (head == NULL)
		return true;
	return false;
}
void list::insert_beg(int v) {
	Node* p = new Node(v);	//p->Data = v;
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
	Node* NewNode = new Node(newvalue);		//NewNode->Data = newvalue;
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
void list::insert_end(int value) {
	Node* p = new Node(value);	//p->Data = value;
	if (isEmpty())
		head = p;
	else
		tail->next = p;
	tail = p;
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
void list::delete_Node(int Value_to_delete) {
	if (isEmpty()) {
		cout << "List is Empty\n"; return;
	}
	else if (!Search_in_List(Value_to_delete, *this)) {
		cout << "Not found in list\n"; return;
	}
	Node* p = head;
	Node* Temp;
	if (Value_to_delete == head->Data) {
		Temp = p;
		head = p->next;
		delete Temp;
		return;
	}
	while (p != NULL)
	{
		if (p->next->Data == Value_to_delete)
		{
			cout << "abr\n";
			Temp = p->next;
			p->next = p->next->next;
			delete Temp;
			if ((p->next == NULL))
				tail = p;
			return;
		}
		p = p->next;
	}
}
int list::Number_of_Nodes() const {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 1;
	Node* p = head;
	while (p != NULL)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}
void list::Display_list() const {
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
//list::~list()
//{
//	Node* p = head;
//	int i = 1, num = Number_of_Nodes();
//	while (i != num)
//	{
//		cout << i<<".  Deleting NODE:" << head->Data << "\t\t";
//		delete_Node(head->Data);
//		Display_list();
//		//p = p->next;
//		i++;
//	}
//}
list::~list() {
	if (isEmpty())
		return;
	else
		cout << "List Not empty\n";
	cout << "Entering ~" << endl;
	Node* p = head;
	Node* q = head->next;
	while (p != NULL)
	{
		cout << "Deleting:" << p->Data << "\t\t";
		if (p->next == NULL) {

			cout << "NOW" << endl;
		}
		delete p;
		p = q;
		if (p != NULL)
			q = q->next;
	}
	cout << "Leaving ~" << endl;
}
