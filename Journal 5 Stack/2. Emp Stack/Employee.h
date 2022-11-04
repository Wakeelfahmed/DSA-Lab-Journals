#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
public:
	string EmpName;
	string EmpID;
	string NIC;
	string Joining_Data;
	long long int Salary;
	int Bonus;
	Employee();
	Employee(string name, string id, string NIC, string Joining_Data, long long int Salary, int Bonus);
	string get_EmpName() const;
	string get_EmpID() const;
	string get_NIC() const;
	string get_Joining_Data() const;
	long long int get_Salary() const;
	int get_Bonus() const;
	void Display_Employee_Details();


};

