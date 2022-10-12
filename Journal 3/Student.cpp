#include"Student.h"


Student::Student() : enrollment(""), name("") {}
Student::Student(string name, string enrollment) : name(name), enrollment(enrollment) {}
void Student::set_enrollment(string enrollment) { this->enrollment = enrollment; }
void Student::set_name(string name) { this->name = name; }
string Student::get_enrollment() const { return enrollment; }
string Student::get_name() const { return name; }
//Student get_Student() const { return *this; }
//bool operator== (Student s1) const;