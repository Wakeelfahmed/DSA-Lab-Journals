#include<iostream>
using namespace std;
#include"Doubly_list.h"
int main() {
	Doubly_list list;
	Employee me("Wakeel", "192", "4210122958249", "22 Oct 2001", 100000, 1000);
	list.push(me);
	Employee me1("Furqan", "192", "4210122958249", "23 Oct 2001", 464664, 1000);
	list.push(me1);
	list.Display_List();
	cout << "poping\n";
	list.pop();
	list.Display_List();
	Employee me2("Ahmed", "192", "4210122958249", "24 Oct 2010", 500000, 1000);
	list.push(me2);
	Employee me4("last", "192", "4210122958249", "24 Oct 2010", 500000, 1000);
	list.push(me4);
	cout << "pushing\n";
	list.Display_List();
}