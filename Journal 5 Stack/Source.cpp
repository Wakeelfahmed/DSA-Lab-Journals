#include<iostream>
using namespace std;
#include"Doubly_list.h"
int main() {
	Doubly_list list;
	Employee me("Wakeel", "192", "4210122958249", "22 Oct 2001", 100000, 1000);
	list.insert_end(me);
	Employee me1("Furqan", "192", "4210122958249", "23 Oct 2001", 464664, 1000);
	list.insert_end(me1);
	Employee me2("Ahmed", "192", "4210122958249", "24 Oct 2010", 500000, 1000);
	list.insert_end(me2);
	list.Display_List();
}