#pragma once
#include"Node.h"
class Doubly_list
{
public:
	Node* head;
	Doubly_list() :head(0) {}
	bool isEmpty();
	void insert_beg(Employee v);
	void insert_end(Employee v);
	void insert_after(Employee prev_Employee, Employee v);
	void remove(string id);
	void update_Salary(long long int newsalary, string employee_id);
	void update_Bonus(long long int newsalary, string employee_id);
	void Display_List();
	void Swap(int pos_i, int pos_j);
	Node* get_Node_by_Pos(int i) const;
	void clear();
};