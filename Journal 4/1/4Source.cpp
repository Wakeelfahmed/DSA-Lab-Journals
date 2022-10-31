#include<iostream>
#include<conio.h>
#include"list.h"
using namespace std;
void Swap(dummpy_header_list& list) {
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
void Print_Even_Nodes(dummpy_header_list list) {
	int position_count = 1;
	Node* p = list.get_head();
	cout << "Even Values are\n";
	while (p != NULL) {
		if (p->Data % 2 == 0)
			cout << p->Data << "\t";
		p = p->next;
	}
}
int Number_of_Nodes(dummpy_header_list list) {
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
void Display_headTail(const dummpy_header_list & list) {
	if (!list.isEmpty())
		cout << "Head:" << list.get_head()->next->Data;
	//<< "\tTail:" << list.get_tail()->Data << endl;// "\tnext:"; << list.get_tail()->next << endl;
}
int main() {
dummpy_header_list mylist;
mylist.insert_beg(10);
mylist.insert_end(1);
mylist.insert_end(2);
mylist.insert_end(3);
mylist.insert_end(4);
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
//mylist.insert_after(2,8);
mylist.Display_list(); mylist.delete_Node(10); 
mylist.Display_list();
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