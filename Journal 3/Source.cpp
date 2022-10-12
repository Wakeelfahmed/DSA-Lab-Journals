#include<iostream>
#include"list.h"
//#include"Node.h"
//#include"Student.h"
//using namespace std;

//int main() { cout << "h"; }
/*void union_of_list(Node* first, Node* second) {

}*/
int main() {
	int input = 0, Newvalue = 0;
	list mylist;
	Student me("wakeel", "01-134212-192");
	mylist.Display_list();
	//mylist.insert_beg(3);	mylist.insert_beg(2);	mylist.insert_beg(1);
	//mylist.insert_beg(0);	mylist.Display_list();	mylist.insert_end(4);
	mylist.Display_list();
	while (1)
	{
		cout << "Enter the value to Delete\n";
		cin >> input;
		//mylist.delete_Node(input);
		mylist.Display_list();
		//if (!mylist.isEmpty())
			//cout << "Head:" << mylist.get_head()->Data << "\tTail:" << mylist.get_tail()->Data << endl;
	}
}
//cout << "There are " << mylist.Number_of_Nodes() << " Nodes in the list" << endl;
//cout << "Maximum_Number_in_List is: " << Maximum_Number_in_List(mylist) << endl;