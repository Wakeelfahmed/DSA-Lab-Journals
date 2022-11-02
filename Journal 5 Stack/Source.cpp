#include<iostream>
using namespace std;
#include"Doubly_list.h"
int main() {
	Doubly_list list;
	list.insert_end(100);
	list.insert_beg(5);
	list.Display_List();
	list.insert_end(109);
	list.Display_List();
	list.insert_beg(3);
	list.insert_beg(2);
	list.insert_beg(1);
	list.Display_List();
	//while (1)
	//{

	//}
}