#pragma once
#pragma once
class Circular_Queue
{
	int* myArray;
	int Size;
	int front, rear, count;
public:
	Circular_Queue(int);
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(int value);
	int dequeue();
	int getFront() const;
	void display() const;
	int get_Queue_Size() const;
};



