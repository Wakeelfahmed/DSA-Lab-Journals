#include<iostream>
#include"list.h"
/*void union_of_list(Node* first, Node* second) {}*/
int Search_in_List(Student student_to_search, list list) {
	Node* p = list.get_head();
	int Position_counter = 1;
	while (p != NULL)
	{
		if (p->Student_Data == student_to_search) {
			cout << "found at position:" << Position_counter << endl;
			return Position_counter;
		}
		p = p->next;
		Position_counter++;
	}
	return 0; // no record found
}
int main() {
	int input = 0, Newvalue = 0;
	list mylist;
	Student me("wakeel", "1");
	Student me1("furqan", "2");
	Student me2("ahmed", "3");
	mylist.Display_list();
	mylist.insert_beg(me2);
	mylist.insert_beg(me1);
	mylist.insert_beg(me);
	mylist.Display_list();
	if (Search_in_List(me1, mylist))
		cout << "Found at:" << Search_in_List(me, mylist) << endl;
	else cout << "Not Found" << endl;
	//mylist.insert_beg(0);	mylist.Display_list();	mylist.insert_end(4);
	while (0)
	{
		cout << "Enter the value to Delete\n";
		cin >> input;
		//mylist.delete_Node(input);
		mylist.Display_list();
		//if (!mylist.isEmpty())
			//cout << "Head:" << mylist.get_head()->Data << "\tTail:" << mylist.get_tail()->Data << endl;
	}
}