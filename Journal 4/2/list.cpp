#include"list.h"
#include<iostream>
using namespace std;
circular_list::circular_list() : Head(NULL) { }
Node* circular_list::get_head() const { return Head; }
bool circular_list::isEmpty() const {
	if (Head == NULL)
		return true;
	return false;
}
void circular_list::insert_beg(int v) {
	Node* NewNode = new Node(v);
	if (isEmpty()) {
		Head = NewNode;
		NewNode->next = Head;
	}
	else {
		NewNode->next = Head;
		Node* p = Head;
		while (p->next != Head)
			p = p->next;
		Head = NewNode;
		p->next = Head;
	}
}
void circular_list::insert_specfic_Position(int Position, int newvalue) {
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
void circular_list::insert_after(int oldvalue, int newvalue) {
	Node* p = Head;
	if (isEmpty())
	{
		return;
	}
	do
	{
		if (p->Data == oldvalue)
		{
			Node* NewNode = new Node(newvalue);
			NewNode->next = p->next;
			p->next = NewNode;
			return;
		}
		p = p->next;
	} while (p != Head);

}
//void circular_list::insert_after(int oldvalue, int newvalue) {
//	Node* temp = Head;
//	if (Head == NULL)
//	{
//		cout << "List is empty"; return;
//	}
//	else if (Head != NULL)
//	{
//		if (Head->Data == oldvalue) {
//			Node* t = new Node;
//			t->Data = newvalue;
//			t->next = temp->next;
//			temp->next = t;
//		}
//		else if (Head->Data != oldvalue)
//		{
//			do {
//				temp = temp->next;
//			} while (temp->Data != oldvalue && temp != Head);
//			if (temp == Head)
//			{
//				cout << "Node not found"; exit(0);
//			}
//			else {
//				Node* t = new Node;
//				t->Data = newvalue;
//				t->next = temp->next;
//				temp->next = t;
//			}
//		}
//		return;
//	}
//}
void circular_list::insert_end(int value) {
	Node* ptr = new Node;
	ptr->Data = value;
	ptr->next = NULL;
	if (Head == NULL)
	{
		Head = ptr;
		ptr->next = Head;
	}
	else
	{
		Node* temp = Head;
		while (temp->next != Head)
		{
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = Head;
	}

}
void circular_list::Display_list() const {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = Head;
	cout << "List: \t";
	do
	{
		cout << p->Data << "\t";
		p = p->next;
	} while (p != Head);
	cout << endl;
	Node* temp = Head;
}
int Search_in_List(int Value_to_search, circular_list& list) {
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
circular_list circular_list::concatenate(const circular_list& list2) {
	circular_list Result = *this;
	Node* p = get_head();	Node* loop2 = list2.get_head();
	while (p->next != get_head())
		p = p->next;

	while (loop2->next != list2.get_head())
		loop2 = loop2->next;

	loop2->next = Head;	//connect last node of list2 to head of list1 making circular

	p->next = list2.get_head();//connect last node of list1 to head of list2.
	cout << "Concatenated list is:\n";
	Result.Display_list();
	return Result;
}
int circular_list::Number_of_Nodes() const {
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
void circular_list::delete_Node(int Value_to_delete) {
	Node* temp = Head, * t = NULL;
	if (Head == NULL) {
		cout << "List is empty"; return;
	}
	if (Head->Data == Value_to_delete)
	{
		if (Head->next == Head) {
			delete temp;
			Head = NULL;
		}
		else {
			do {
				t = temp;
				temp = temp->next;
			} while (temp != Head);
			Head = Head->next;
			delete temp; t->next = Head;
		}
	}
	else {
		do {
			t = temp;
			temp = temp->next;
		} while (temp->Data != Value_to_delete && temp != Head);
		if (temp->Data == Value_to_delete)
		{
			t->next = temp->next;
			delete temp;
		}
		else { cout << "Node not found"; return; }
	}
}
circular_list::~circular_list() {
	cout << "EN\n";
	if (isEmpty())
		return;
	Node* p = Head;
	Node* q = Head->next;
	while (p != NULL)
	{
		if (p->next == Head) {
			cout << "Leaving\n";
			return;
		}
		delete p;
		p = q;
		if (p != NULL)
			q = q->next;
	}
	cout << "Leaving\n";
}