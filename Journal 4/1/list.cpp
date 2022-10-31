#include"list.h"
#include<iostream>
using namespace std;
dummpy_header_list::dummpy_header_list() {
	Head = new Node;
	Head->Data = -1;
	Head->next = NULL;
}
Node* dummpy_header_list::get_head() const { return Head; }
bool dummpy_header_list::isEmpty() const {
	if (Head->next == NULL)
		return true;
	return false;
}
void dummpy_header_list::insert_beg(int v) {
	Node* p = new Node(v);	//p->Data = v;
	if (isEmpty())
		head->next = p;
	else {
		p->next = head->next; head->next = p;
	}
	//head->next = p;
}
void dummpy_header_list::insert_specfic_Position(int Position, int newvalue) {
	int position_count = 1;
	if (Position > Number_of_Nodes()) {
		cout << "List has less nodes than the place, Node CAN't be inserted!!\n";
		return;
	}
	Node* NewNode = new Node(newvalue);		//NewNode->Data = newvalue;
	Node* p = Head;
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
void dummpy_header_list::insert_after(int oldvalue, int newvalue) {
	if (isEmpty())
	{
		cout << "List is Empty"; return;		//Wrong
	}
	Node* p = Head->next;				//Wrong
	while (p->Data != oldvalue && p != NULL)
	{
		p = p->next;
	}
	if (p == NULL) { cout << "Node not found"; exit(0); }		//Wrong
	Node* q = new Node(newvalue);	//q->Data = newvalue;		//Wrong
	q->next = p->next;
	p->next = q;
}								//Wrong
void dummpy_header_list::insert_end(int value) {
	Node* p = new Node(value);	//p->Data = value;
	Node* t = Head;	//p->Data = value;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = p;
	//tail = p;
}
int Search_in_List(int Value_to_search, dummpy_header_list& list) {
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
void dummpy_header_list::delete_Node(int Value_to_delete) {
	if (isEmpty()) {
		cout << "List is Empty\n"; return;
	}
	if (!Search_in_List(Value_to_delete, *this)) {
		cout << "Not found in list\n"; return;
	}
	Node* p = Head->next;
	Node* Temp;
	if (Value_to_delete == (p->Data)) {
		Temp = p;
		Head->next = p->next;
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
			//if ((p->next == NULL))
				//tail = p;
			return;
		}
		p = p->next;
	}
}
int dummpy_header_list::Number_of_Nodes() const {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 0;
	Node* p = Head;
	while (p != NULL)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}
void dummpy_header_list::Display_list() const {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = Head->next;
	cout << "here" << p->next->Data << endl;
	cout << "List: \t";
	while (p != NULL)
	{
		cout << p->Data << "\t";
		p = p->next;
	}	Node* test = Head->next;

	cout << endl;	cout << "\nfter" << test->next->Data << endl;

}
dummpy_header_list::~dummpy_header_list() {
	if (isEmpty())
		return;
	//cout << "Entering ~" << endl;
	Node* p = Head;
	Node* q = Head->next;
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
