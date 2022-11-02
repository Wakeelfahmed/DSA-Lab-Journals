#include "Employee.h"
Employee::Employee() : EmpName(""), EmpID(""), NIC(""), Joining_Data(""), Salary(0), Bonus(0) {}
Employee::Employee(string name, string id, string NIC, string Joining_Data, long long int Salary, int Bonus)
:	EmpName (name), EmpID(id), NIC(NIC), Joining_Data(Joining_Data), Salary(Salary), Bonus(Bonus) {}