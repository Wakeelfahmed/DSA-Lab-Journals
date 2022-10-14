#include<iostream>
#include<conio.h>
#include"list.h"
void Display_headTail(list list) {
	if (!list.isEmpty())
		cout << "Head:" << list.get_head()->Data
		<< "\tTail:" << list.get_tail()->Data << endl;
}
list mylist;
void Swap(list& list) {
	int TEMPVALUE;
	Node* Temp;
	int Half_of_list = list.Number_of_Nodes() / 2;
	int position_count = 1;
	Node* p = list.get_head();
	while (!(position_count > Half_of_list)) {	//p!= NULL && !(position_count > Half_of_list)
		//TEMPVALUE = p->Data;
		Temp = p->next;
		list.insert_end(p->Data);//		list.insert_end(TEMPVALUE);
		list.delete_Node(p->Data);
		p = Temp;
		position_count++;
	}
	cout << "LEAVING LOOP";
}
int main() {
	int input;
	mylist.insert_beg(3);
	mylist.insert_beg(2);
	mylist.insert_beg(1);
	mylist.insert_beg(4);
	mylist.insert_beg(5);
	mylist.insert_beg(6);
	//mylist.delete_Node(2);
	mylist.Display_list();
	Swap(mylist);
	mylist.Display_list();
	while (1)
	{
		cout << "Enter the value to Delete\n";
		cin >> input;
		mylist.delete_Node(input);
		mylist.Display_list();
		if (!mylist.isEmpty())
			cout << "Head:" << mylist.get_head()->Data << "\tTail:" << mylist.get_tail()->Data << endl;
	}
}