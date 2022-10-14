#include"Student.h"

Student::Student() : enrollment(""), name("") {}
Student::Student(string name, string enrollment) : name(name), enrollment(enrollment) {}
void Student::set_enrollment(string enrollment) { this->enrollment = enrollment; }
void Student::set_name(string name) { this->name = name; }
string Student::get_enrollment() const { return enrollment; }
string Student::get_name() const { return name; }
//Student get_Student() const { return *this; }
bool Student::operator==(Student Student_2) const
{
	if (enrollment == Student_2.enrollment && name == Student_2.name)
		return 1;
	return 0;
}