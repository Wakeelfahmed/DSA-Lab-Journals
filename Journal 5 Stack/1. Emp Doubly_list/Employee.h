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
};

