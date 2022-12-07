#include "Dynamic_Queue.h"
#include<iostream>
using namespace std;
bool Dynamic_Queue::isEmpty() const {
	if (Queue.Number_of_Nodes() == 0)	
		return true; return false;
}
void Dynamic_Queue::Insert_Right(int value) {
	Queue.insert_end(value);
}
void Dynamic_Queue::Insert_Left(int value) {
	Queue.insert_beg(value);
}
int Dynamic_Queue::Remove_Left() {
	int temp = Queue.get_head()->Data;
	Queue.delete_Node(temp);
	return  temp;
}
int Dynamic_Queue::Remove_Right() {
	int temp = Queue.get_Last_Node()->Data;
	Queue.delete_Node(temp);
	return  temp;
}
int Dynamic_Queue::getFront() const {
	if (isEmpty())
		cout << "Queue is empty" << endl;
	else
		return  Queue.get_head()->Data;
}
void Dynamic_Queue::display() const {
	if (isEmpty())
		cout << "Queue is empty" << endl;
	else
		Queue.Display_list();
}