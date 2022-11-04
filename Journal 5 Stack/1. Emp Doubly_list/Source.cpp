#include<iostream>
#include"Doubly_list.h"
using namespace std;
int Number_of_Nodes(const Doubly_list list) {
	int i = 0;
	Node* p = list.head;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
void Sort(Doubly_list& List) {
	int j, loop;
	int Nodes_count = Number_of_Nodes(List);
	cout << "List Before Sorting\n";
	List.Display_List();
	for (loop = 1; loop <= Nodes_count; loop++) {
		for (j = 1; j <= Nodes_count - loop; j++)
			if (List.get_Node_by_Pos(j)->data.get_Salary() > List.get_Node_by_Pos(j + 1)->data.get_Salary() == 1)
				List.Swap(j, j + 1);

	}
	cout << "\nSorted List:\n";
}
int main() {
	Doubly_list list;
	Employee me("Wakeel Ahmed", "192", "4210122958249", "22 Oct 2001", 100000, 1000);
	Employee me3("employee 2", "195", "4210122958249", "24 Oct 2010", 600, 1000);
	Employee me4("employee 3", "196", "4210122958249", "24 Oct 2010", 400, 1000);
	Employee me5("employee 4", "197", "4210122958249", "24 Oct 2010", 500000, 1000);
	list.insert_end(me);
	list.insert_end(me3);
	list.insert_end(me4);
	list.insert_end(me5);
	list.Display_List();
	Sort(list);
	list.Display_List();
	string s1; //int i;
	Employee e;
	cout << "Clearing list\n";
	list.clear();
	list.Display_List();
	int input[2];
	int newsalary;
	while (0)
	{
		list.Display_List();
		cout << "Select nodes to update Bonus:"; cin >> input[0];
		cout << "Enter New Bonus:"; cin >> newsalary;
		list.update_Bonus(newsalary, list.get_Node_by_Pos(input[0])->data.get_EmpID());
	}
}