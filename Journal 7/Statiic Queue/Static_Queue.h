#pragma once
class Static_Queue
{
	int* myArray;
	int Size;
	int front, rear;
public:
	Static_Queue(int);
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(int value);
	int dequeue();
	int getFront() const;
	void display() const;
	int get_Queue_Size() const;
};

