#include<iostream>
#include<conio.h>
#include"circular_list.h"
using namespace std;
void Display_headTail(circular_list & list) {
	if (!list.isEmpty()) {
		cout << "Head:" << list.get_head()->next->Data
			<< "\tLast->next:";// << list()->Data << endl;// "\tnext:"; << list.get_tail()->next << endl;
		Node* p = list.get_head();
		do
		{
			p = p->next;
		} while (p != list.get_head());
		cout << p->Data << endl;
	}
}
int main() {
	circular_list mylist, mylist2, ans;
	mylist.insert_end(95);
	cout << "deleting 96\n"; mylist.delete_Node(96);
	Display_headTail(mylist);
	mylist.Display_list();
	mylist.insert_beg(4);
	mylist.Display_list();;
	Display_headTail(mylist);
	cout << "deleting 4\n"; mylist.delete_Node(4);
	mylist.Display_list();
	cout << "deleting 95\n"; mylist.delete_Node(95);
	mylist.Display_list();
	mylist.insert_end(97);
	mylist.Display_list();
	cout << "deleting 97\n"; mylist.delete_Node(97);
	mylist.Display_list();
	mylist.insert_end(98);
	mylist.Display_list();
	cout << "deleting 98\n"; mylist.delete_Node(98);
	mylist.Display_list();
	mylist.insert_end(99);
	mylist.Display_list();
	mylist.insert_beg(2);
	mylist.insert_beg(1);
	mylist.Display_list();
	//Display_headTail(mylist);
	mylist.insert_end(100);
	mylist.Display_list();
}