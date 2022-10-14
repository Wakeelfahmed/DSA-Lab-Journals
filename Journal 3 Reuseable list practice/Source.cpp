#include<iostream>
#include"list.h"
/*void union_of_list(Node* first, Node* second) {}*/
int Search_in_List(string enroll, list list) {
	Student_Node* p = list.get_head();
	int Position_counter = 1;
	while (p != NULL)
	{
		if (p->Student_Data.get_enrollment() == enroll) {
			cout << "Student Name:" << p->Student_Data.get_name() << endl;
			cout << "found at position:" << Position_counter << endl;
			return Position_counter;
		}
		p = p->next;
		Position_counter++;
	}
	return 0; // no record found
}
/*int Search_in_List(Student student_to_search, list list) {
	Student_Node* p = list.get_head();
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
}*/
void Display_headTail(list list) {
	if (!list.isEmpty())
		cout << "Head:" << list.get_head()->Student_Data.get_name()
		<< "\tTail:" << list.get_tail()->Student_Data.get_name() << endl;
}
int main() {
	int input = 0, Newvalue = 0;
	list mylist;
	Student me("wakeel", "1");
	Student me1("furqan", "2");
	Student me2("ahmed", "3");
	Student last("last", "3");

	Student_Node* Node = new Student_Node; Node->set_Student(me);
	Student_Node* Node1 = new Student_Node; Node1->set_Student(me1);
	Student_Node* Node2 = new Student_Node; Node2->set_Student(me2);
	Node2->set_Student(last);

	mylist.Display_list();
	mylist.insert_beg(&Node2);
	Display_headTail(mylist);
	mylist.insert_beg(&Node1);
	Display_headTail(mylist);
	mylist.insert_beg(&Node);
	Display_headTail(mylist);
	mylist.insert_end(&Node2);
	mylist.Display_list();
	if (Search_in_List("1", mylist))
		cout << "Found at:" << Search_in_List("1", mylist) << endl;
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