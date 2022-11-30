#include<iostream>
#include<string.h>
#include"Stack.h"
using namespace std;
void Decimal_To_Binary(int number) {
	Stack<int>obj;
	if (number > 0) {
		while (number > 0)
		{
			int rem = number % 2;
			number = number / 2;
			obj.push(rem);
		}
	}
	else
	{
		cout << "Enter Positive Number"; return;
	}
}
void Evaluation_Postfix(string Expression) {
	Stack <char> obj;
	for (int i = 0; i < Expression.length(); i++)
	{
		if (isdigit(Expression[i])) {
			int num = Expression[i] - '0';
			obj.push(num);
		}
		else
		{
			if (Expression[i] == '+')
			{
				int num1 = obj.pop();
				int num2 = obj.pop();
				int result = num1 + num2;
				obj.push(result);
			}
			if (Expression[i] == '-')
			{
				int num1 = obj.pop();
				int num2 = obj.pop();
				int result = num2 - num1;
				obj.push(result);
			}
			if (Expression[i] == '/')
			{
				int num1 = obj.pop();
				int num2 = obj.pop();
				int result = num2 / num1;
				obj.push(result);
			}
			if (Expression[i] == '*')
			{
				int num1 = obj.pop();
				int num2 = obj.pop();
				int result = num2 * num1;
				obj.push(result);
			}
		}
	}
	while (obj.get_top() != -1)
		cout << obj.pop() << " ";
}
string Reverse_String(string String_To_Reverse) {
	Stack<char>obj;
	for (int i = 0; i < String_To_Reverse.size(); i++)
		obj.push(String_To_Reverse[i]);
	for (int i = 0; i < String_To_Reverse.size(); i++)
		String_To_Reverse[i] = obj.pop();
	cout << "Reversed String: " << String_To_Reverse << endl;
	return String_To_Reverse;
}
bool balanced_Expression(string Expression) {
	Stack<char>obj;
	for (int i = 0; i < Expression.length(); i++)
	{
		//cout << "Stack is ->";
		//obj.Display_Stack();
		if (Expression[i] == '(') {
			obj.push(Expression[i]);
		}
		else if (Expression[i] == ')')
		{
			if (obj.get_top() == -1)
			{
				return 0;
			}
			while (obj.arr[obj.top] != '(' || obj.arr[obj.top] == '(')
			{
				//cout << "Poping\n";
				obj.pop();
				//obj.Display_Stack();
				break;
			}
		}
	}
	//cout << "Final Stack at" << obj.get_top() << endl;
	//obj.Display_Stack();
	if (obj.get_top() == -1)
		return 1;
		//cout << "balanced expression" << endl;
	else
		return 0;
	//cout << "Unbalanced expression" << endl;
}

int main() {
	string Expression;
	cout << "Enter expr to check:";
	cin >> Expression;
	Stack<int>obj;
	//obj.push(1);
	//obj.Display_Stack();
	//obj.push(2);
	//obj.Display_Stack();
	//obj.push(3);
	//obj.Display_Stack();
	//obj.push(4);
	//obj.Display_Stack();
	bool ans = balanced_Expression(Expression);
	if (ans)
		cout << "balanced expression" << endl;
	else
		cout << "Unbalanced expression" << endl;

}
