#include<iostream>
#include"Stack.h"
#include"Dynamic Queue/Dynamic_Queue.h"
using namespace std;
int main() {
	string astring;
	Stack <char> Stack;
	Dynamic_Queue Queue;
	while (1)
	{
		cout << "Enter String to check for palindrome: ";
		cin >> astring;
		for (int i = 0; i < astring.length(); i++)
		{
			Stack.push(astring[i]);
			Queue.Insert_Right(astring[i]);
		}
		bool check = 1;
		for (int i = 0; i < astring.length(); i++)
		{
			if (Stack.pop() != Queue.Remove_Left()) {
				check = 0; 
				Stack.top = -1;	//empty the stack
				Queue.Empty_Queue(); //empty the Queue
				break;
			}
		}
		if (check)
			cout << "Palidome\n";
		else
			cout << "Not Palidome\n";
	}
}