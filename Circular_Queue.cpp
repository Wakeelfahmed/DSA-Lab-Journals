#include "Circular_Queue.h"
#include "Static_Queue.h"
#include<iostream>
using namespace std;
Circular_Queue::Circular_Queue(int s)
{
	myArray = new int[s];
	Size = s;
	front = rear = count = 0;
}
bool Circular_Queue::isEmpty() const {
	if (front == rear)	//front == size -1 || front == rear
		return true; return false;
}
bool Circular_Queue::isFull() const {
	if (rear == Size - 1)
		return true; return false;
}
void Circular_Queue::enqueue(int value) {
	if (isFull()) {
		cout << "Queue Overflow" << endl;
		return;
	}
	else
		myArray[++rear] = value;
}
int Circular_Queue::dequeue() {
	if (isEmpty())
	{
		cout << "Queue Underflow" << endl;
		return -1;
	}
	else
		return  myArray[++front];
}
int Circular_Queue::getFront() const {
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	else
		return  myArray[front + 1];
}
void Circular_Queue::display() const {
	if (isEmpty())
		cout << "Queue is empty" << endl;
	else
		for (int i = front + 1; i <= rear; i++)
			cout << myArray[i] << "\t";
	cout << endl;
}
int Circular_Queue::get_Queue_Size() const {
	return Size;
}