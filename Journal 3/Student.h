#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
//public:
public:
	string enrollment;
	string name;
	Student();
	Student(string name, string enrollment);
	void set_enrollment(string enrollment);
	void set_name(string name);
	string get_enrollment() const;
	string get_name() const;
	//Student get_Student() const { return *this; }
	//bool operator== (Student s1) const;
};
/*bool Student::operator==(Student Student_2) const
{
	if (enrollment == Student_2.enrollment && name == Student_2.name)
		return 1;
	return 0;
}*/


