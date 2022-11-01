#include<iostream>
#include<conio.h>
#include"dummy_header_list.h"
using namespace std;
void Swap(dummy_header_list& list) {
	Node* Temp;
	int Half_of_list = list.Number_of_Nodes() / 2;
	int position_count = 1;
	Node* p = list.get_head();
	while (!(position_count > Half_of_list)) {
		Temp = p->next;
		list.insert_end(p->Data);
		list.delete_Node(p->Data);
		p = Temp;
		position_count++;
	}
}
void Print_Even_Nodes(dummy_header_list list) {
	int position_count = 1;
	Node* p = list.get_head();
	cout << "Even Values are\n";
	while (p != NULL) {
		if (p->Data % 2 == 0)
			cout << p->Data << "\t";
		p = p->next;
	}
}
int Number_of_Nodes(dummy_header_list list) {
	if (list.isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 0;
	Node* p = list.get_head();
	while (p != NULL)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}
int Maximum_Number_in_List(Node* head) {
	if (head == NULL)
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	Node* p = head;
	int Maximum_Number = p->Data;
	while (p != NULL)
	{
		if (Maximum_Number < p->Data)
		{
			Maximum_Number = p->Data;
		}
		p = p->next;
	}
	return Maximum_Number;
}
void Display_headTail(const dummy_header_list& list) {
	if (!list.isEmpty())
		cout << "Head:" << list.get_head()->next->Data << "Last Node:";
	Node* p = list.get_head();
	while (p->next != NULL)
	{

		p = p->next;
	}
	cout << p->Data << endl;
}
void Reverse_list(dummy_header_list & list) {
	Node* LastNode, * p = list.get_head()->next;
	//dummy_header_list Reversed_list = list;
	/*dummy_header_list Reversed_list;
	Reversed_list = list;*/
	//cout << "New list is :";
	//Reversed_list.Display_list();
	while (p->next != NULL)
		p = p->next;
	LastNode = p;

	p = list.get_head();
	int i = 1;
	//Reversed_list.insert_beg(list.get_head()->Data);
	while (p->Data != LastNode->Data)
	{
		cout << "ROUND " << i << endl;
		list.insert_after(LastNode->Data, list.get_head()->next->Data);
		list.delete_Node(list.get_head()->next->Data);
		p = list.get_head();
		/*Reversed_list.insert_after(LastNode->Data, Reversed_list.get_head()->next->Data);
		Reversed_list.delete_Node(Reversed_list.get_head()->next->Data);
		Reversed_list.Display_list();
		cout << endl;
		p = Reversed_list.get_head();*/
		p = p->next;
		i++;
	}
	cout << "Reversed list\n";
	list.Display_list();
	cout << "org\n";
	list.Display_list();
	cout << "leaving\n";
	//return Reversed_list;
}
int main() {
	dummy_header_list mylist;
	mylist.insert_beg(10);
	mylist.insert_after(10,9);
	mylist.insert_after(9,8);
	mylist.insert_after(8,7);
	mylist.insert_after(7,6);
	mylist.Display_list();
	//mylist.delete_Node(10);
	/*mylist.Display_list();
	mylist.insert_end(1);
	mylist.insert_end(2);
	mylist.insert_end(3);
	mylist.insert_end(4);*/
	//Display_headTail(mylist); cout << endl;//byValue
		//	int input;
		//while (1)
		//{
		//	cout << "Delete Node? ";  input = _getch() - '0';
		//	mylist.delete_Node(input);
		//	mylist.Display_list();
		//	Display_headTail(mylist);
		//}
	//mylist.insert_beg(12);
	mylist.Display_list(); //mylist.delete_Node(7);
	mylist.Display_list();
	//cout << "calling\n";
	Reverse_list(mylist);
	cout << "BACK TO MAIN\n";
	int delete_V;
	while (1)
	{
		mylist.Display_list();
		cout << "Enter value to delete"; cin >> delete_V;
		mylist.delete_Node(delete_V);
	}
}
/*
for (size_t i = 10; i > 0; i--)
{
	mylist.insert_beg(i);
}
mylist.Display_list();
mylist.~list();
mylist.Display_list();
cout << "Maximum Number in List is:" <<
	Maximum_Number_in_List(mylist.get_head()) << endl;


while (0)
{
	cout << "Enter the value to Delete\n";
	cin >> input;
	mylist.delete_Node(input);
	mylist.Display_list();
	if (!mylist.isEmpty())
		cout << "Head:" << mylist.get_head()->Data << "\tTail:" << mylist.get_tail()->Data << endl;
}
*/