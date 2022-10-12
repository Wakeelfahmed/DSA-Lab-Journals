#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
private:
	string enrollment;
	string name;
public:
	Student();
	Student(string name, string enrollment);
	void set_enrollment(string enrollment);
	void set_name(string name);
	string get_enrollment() const;
	string get_name() const;
	//Student get_Student() const { return *this; }
	bool operator== (Student s1) const;
};


