#include<iostream>
#include"Dynamic_Queue.h"
#include"circular_list.h"
using namespace std;
int main() {
	Dynamic_Queue Queue;
	cout << "Inserting right 5 to 10\n";
	for (size_t i = 0; i < 5; i++)
	{
		Queue.Insert_Right(i);
		Queue.display();
	}
	cout << "Inserting left 0 to 4\n";
	for (size_t i = -1; i > -5; i--)
	{
		Queue.Insert_Left(i);
		Queue.display();
	}
	cout << "\nDequeuing 4 times from left\n";
	for (size_t i = 0; i < 4; i++)
	{
		Queue.display();
		Queue.Remove_Left();
	}
	cout << "\nDequeuing 4 times from Right\n";
	for (size_t i = 0; i < 4; i++)
	{
		Queue.display();
		Queue.Remove_Right();
	}
		Queue.display();
}