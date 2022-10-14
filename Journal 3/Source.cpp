#include<iostream>
#include<conio.h>
#include"list.h"
/*void union_of_list(Node* first, Node* second) {}*/
int Search_in_List_by_enroll(list list) {
	string enroll;
	cout << "Enter ID to find student:";
	cin >> enroll;
	Node* p = list.get_head();
	int Position_counter = 1;
	while (p != NULL)
	{
		if (p->Student_Data.get_enrollment() == enroll) {
			cout << "found at position:" << Position_counter << endl;
			cout << "Student Name:" << p->Student_Data.get_name() << endl;
			return Position_counter;
		}
		p = p->next;
		Position_counter++;
	}
	return 0; // no record found
}
void Display_headTail(list list) {
	if (!list.isEmpty())
		cout << "Head:" << list.get_head()->Student_Data.get_name()
		<< "\tTail:" << list.get_tail()->Student_Data.get_name() << endl;
}
void Validate_Input(int start, int& input, int end) {
	while (input < start || input > end)
		input = _getch() - '0';
}
int input = 0, Newvalue = 0, Input[2];
list mylist;
Student student, student2;
string name, enroll;
void Main_Menu() {
	cout << "1. Add Student Record\t2. Search Student\t 3.Delete Student\t4. Display All Record\t5. Exit" << endl;
	Input[0] = _getch() - '0'; Validate_Input(1, Input[0], 5);
}
void get_Input_for_student(Student& student) {
	cout << "Student Details\nEnter Name:";	cin >> name;
	cout << "Enter Enrollment:"; cin >> enroll;
	student.set_Student_Detail(name, enroll);
}
int main() {
	Main_Menu();
	while (Input[0] == 1 || Input[0] == 2 || Input[0] == 3 || Input[0] == 4)
	{
		switch (Input[0])
		{
		case 1: {
			system("CLS");
			get_Input_for_student(student);
			cout << "Select where to Insert in the list\n";
			cout << "1. Beginning\t\t2. Spectific Position\t\t3. After\t\t4. End" << endl;
			Input[1] = _getch() - '0';
			if (Input[1] == 1)
				mylist.insert_beg(student);
			else if (Input[1] == 2) {
				cout << "Enter Position:"; 		Input[1] = _getch() - '0';
				mylist.insert_specfic_Position(Input[1], student);
			}
			else if (Input[1] == 3) {
				cout << "Enter after whom to insert:"; 		Input[1] = _getch() - '0';
				cout << "Enter Name";	cin >> name;
				cout << "Enter Enrollment"; cin >> enroll;
				student2.set_Student_Detail(name, enroll);
				mylist.insert_after(student2, student);
			}
			else if (Input[1] == 4)
				mylist.insert_end(student);
			break;
		}
		case 2: {
			system("CLS");
			if (!Search_in_List_by_enroll(mylist))
				//cout << "Found at:" << Search_in_List_by_enroll(mylist) << endl;
				cout << "Does not exist in Records" << endl;
			break;
		}
		case 3: {
			system("CLS");
			cout << "Enter Detail of Student record to be deleted" << endl;
			get_Input_for_student(student);
			mylist.delete_Student(student);
			mylist.Display_list();
			break;
		}
		case 4: {
			system("CLS");
			mylist.Display_list();
			break;
		}
		}
		cout << "\n";
		Main_Menu();
	}
}