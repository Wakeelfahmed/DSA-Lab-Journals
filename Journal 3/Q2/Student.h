#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
private:
	string name;
	string enrollment;
public:
	Student();
	Student(string name, string enrollment);
	void set_enrollment(string enrollment);
	void set_name(string name);
	string get_enrollment() ;
	string get_name();
	void set_Student_Detail(string name, string enroll);
	bool operator== (Student s1) const;
};