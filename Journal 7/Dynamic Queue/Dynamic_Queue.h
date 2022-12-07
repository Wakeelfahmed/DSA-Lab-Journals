#pragma once
#include"circular_list.h"
class Dynamic_Queue
{
	circular_list Queue;
public:
	bool isEmpty() const;
	void Insert_Right(int value);
	void Insert_Left(int value);
	int Remove_Left();
	int Remove_Right();
	int getFront() const;
	void display() const;
	void Empty_Queue();
};