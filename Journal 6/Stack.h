#pragma once
#include<iostream>
using namespace std;
const int Size = 20;
template <class T>
class Stack
{
public:
	//private:
	T arr[Size];
	int top;
	Stack() : top(-1) {}
	void push(T v) {
		if (top == Size - 1)
			cout << "OverFlow\n";
		else
			arr[++top] = v;
	}
	T pop() {
		if (top == -1)
			cout << "Underflow";
		else
			return arr[top--];
	}
	int get_top() const { return top; }
	int get_top_Value() const { return arr[top]; }
	void Display_Stack() {
		Stack obj; int i = 0;
		cout << "Stack:\n";
		while (top != -1)
		{
			cout << arr[top] << endl;
			obj.push(pop());
			i++;
		}cout << endl;
		while (obj.get_top() != -1)
		{
			push(obj.pop());
		}
	}
};