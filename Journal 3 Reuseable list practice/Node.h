#pragma once
#include"Student.h"
class Student_Node
{
public:
	Student Student_Data;
	Student_Node* next;
	Student_Node();
	void set_Student(Student NewStudent) {
		Student_Data = NewStudent;
	}
};