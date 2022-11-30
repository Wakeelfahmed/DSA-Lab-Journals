#include "Employee.h"
Employee::Employee() : EmpName(""), EmpID(""), NIC(""), Joining_Data(""), Salary(0), Bonus(0) {}
Employee::Employee(string name, string id, string NIC, string Joining_Data, long long int Salary, int Bonus)
	: EmpName(name), EmpID(id), NIC(NIC), Joining_Data(Joining_Data), Salary(Salary), Bonus(Bonus) {}
void Employee::Display_Employee_Details() {
	cout << "NIC:" << NIC
		<< "\tName:" << EmpName
		<< "\tID:" << EmpID
		<< "\tJOD:" << Joining_Data
		<< "\tSalary:" << Salary
		<< "\tBouns:" << Bonus << endl;
}
string Employee::get_EmpName() const { return EmpName; }
string Employee::get_EmpID() const { return EmpID; }
string Employee::get_NIC() const { return NIC; }
string Employee::get_Joining_Data() const { return Joining_Data; }
long long int Employee::get_Salary() const { return Salary; }
int Employee::get_Bonus() const { return Bonus; }