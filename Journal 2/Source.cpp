#include<iostream>
#include"list.h"
using namespace std;
int Maximum_Number_in_List(list mylist) {
	if (mylist.isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	Node* p = mylist.get_head();
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
int main() {
	int input = 0, Newvalue = 0;
	list mylist;
	mylist.Display_list();
	mylist.insert_beg(3);	mylist.insert_beg(2);	mylist.insert_beg(1);
	mylist.insert_beg(0);	mylist.Display_list();	mylist.insert_end(4);
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
//cout << "There are " << mylist.Number_of_Nodes() << " Nodes in the list" << endl;
//cout << "Maximum_Number_in_List is: " << Maximum_Number_in_List(mylist) << endl;