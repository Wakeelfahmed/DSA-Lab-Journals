#include"dummy_header_list.h"
#include<iostream>
using namespace std;
dummy_header_list::dummy_header_list() {
	head = new Node(-1); //any value and a head points to NULL
}
Node* dummy_header_list::get_head() const { return head; }
int dummy_header_list::get_Node_Data(int Position_of_Node) {
	Node* p = head;
	int pos = 1;
	while (p!= NULL)
	{
		if (pos == Position_of_Node)
		{
			return p->Data;
		}
		p = p->next;
		pos++;
	}
}

bool dummy_header_list::isEmpty() const {
	if (head->next == NULL)
		return true;
	return false;
}
void dummy_header_list::insert_beg(int v) {
	Node* p = new Node(v);
	if (isEmpty())
		head->next = p;
	else {
		p->next = head->next;
		head->next = p;
	}
}
void dummy_header_list::insert_specfic_Position(int Position, int newvalue) {
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
int Search_in_List(int Value_to_search, dummy_header_list& list) {
	Node* p = list.get_head()->next;
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
void dummy_header_list::insert_after(int oldvalue, int newvalue) {
	if (isEmpty())
	{
		cout << "List is Empty"; return;		//Wrong
	}
	if (!Search_in_List(oldvalue, *this))
	{
		cout << "Node not found"; return;
	}		//Wrong
	Node* p = head->next;				//Wrong
	Node* NewNode = new Node(newvalue);
	//if (head->next->Data == oldvalue && head->next->next == NULL) {
	//	cout << "1 Node exists\n";
	//	head->next->next = NewNode;
	//	return;
	//}
	while (p != NULL)
	{
		if (p->Data == oldvalue)
		{
			NewNode->next = p->next;
			p->next = NewNode;
			return;
		}
		p = p->next;
	}
}
void dummy_header_list::insert_end(int value) {
	Node* p = new Node(value);	//p->Data = value;
	Node* t = head;	//p->Data = value;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = p;
	//tail = p;
}
void dummy_header_list::delete_Node(int Value_to_delete) {
	if (isEmpty()) {
		cout << "List is Empty\n"; return;
	}
	if (!Search_in_List(Value_to_delete, *this)) {
		cout << "Not found in list\n"; 
		cout << "pos" << Search_in_List(Value_to_delete, *this) << endl;
		return;
	}
	Node* p = head->next;
	Node* Temp;
	if (Value_to_delete == (p->Data)) {
		Temp = p;
		head->next = p->next;
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
			return;
		}
		p = p->next;
	}
}
int dummy_header_list::Number_of_Nodes() const {
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
void dummy_header_list::Display_list() const {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = head->next;
	cout << "List: \t";
	while (p != NULL)
	{
		cout << p->Data << "\t";
		p = p->next;
	}	Node* test = head->next;
	cout << endl;
}
dummy_header_list::~dummy_header_list() {
	if (isEmpty())
		return;
	//cout << "Entering ~" << endl;
	Node* p = head;
	Node* q = head->next;
	while (p != NULL)
	{
		//	cout << "Deleting:" << p->Data << "\t\t";
		if (p->next == NULL) {

			//cout << "NOW" << endl;
		}
		delete p;
		p = q;
		if (p != NULL)
			q = q->next;
	}
	//cout << "Leaving ~" << endl;
}
dummy_header_list::dummy_header_list(const dummy_header_list& i) {
	head = i.head;
	cout << "Copy constructor called " << endl;
}
dummy_header_list& dummy_header_list::operator=(const dummy_header_list& t)
{
	cout << "Assignment operator called \n";
	return *this;
}