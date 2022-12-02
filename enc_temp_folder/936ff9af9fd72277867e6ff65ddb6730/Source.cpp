#include<conio.h>
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
int Get_Precendence(char elem)
{
	switch (elem)
	{
	case '#': return 0;
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	}
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
		if (Expression[i] == '(')
			obj.push(Expression[i]);
		else if (Expression[i] == ')')
		{
			if (obj.get_top() == -1)
				return 0;
			while (obj.arr[obj.top] != '(' || obj.arr[obj.top] == '(')
			{
				obj.pop();
				break;
			}
		}
	}
	if (obj.get_top() == -1)
		return 1;
	else
		return 0;
}
string infix_To_postfix(string Expression) {
	Stack<char> Operator;
	string Postfix;
	/*	RULES:
		1)  '(' pushed directly
		2)  num/alpha appended to output directly
		3)  *, /, -, +, ^ can be pushed on '('
		4   ^ can be pushed over +, - , *
			* cant come over ^ , *, /
			/ CANT come over *, /
	*/
	for (int i = 0; i < Expression.length(); i++)
	{
		if (isalnum(Expression[i])) {
			Postfix += Expression[i];
			if (isalnum(Expression[i + 1])) {
				Postfix += Expression[i + 1];
				i++;
			}
			Postfix += " ";
		}
		else if (Expression[i] == ')')
			while (Operator.get_top() != -1)
			{
				if (Operator.get_top_Value() == '(') {
					cout << "Poped (\n";
					Operator.pop();
					break;
				}
				cout << "Inserting in ans:" << Operator.get_top_Value() << endl;
				Postfix += Operator.pop(); Postfix += " ";
			}
		else if (Expression[i] == '(') {
			Operator.push('(');
			cout << "Pushed (\n";
		}
		else if (Expression[i] == '-' || Expression[i] == '+' || Expression[i] == '/'
			|| Expression[i] == '*' || Expression[i] == '(' || Expression[i] == ')')
		{
			if (
				((Expression[i] == '+' || Expression[i] == '-') && Operator.get_top_Value() == '*')
				|| ((Expression[i] == '+' || Expression[i] == '-') && Operator.get_top_Value() == '/')
				|| ((Expression[i] == '+' || Expression[i] == '-') && Operator.get_top_Value() == '/')
				|| Expression[i] == Operator.get_top_Value()
				|| Expression[i] == '/' && Operator.get_top_Value() == '*')
			{
				//4)  + & - CANT come over ^, *, / +, -   
				//		pop until it reaches less precedence one and append to OUT & push 
				cout << "entering\n";
				while (Operator.get_top() != -1) {
					if (
						((Expression[i] == '+' || Expression[i] == '-') && Operator.get_top_Value() == '(')
						|| ((Expression[i] == '/' || Expression[i] == '*') && (Operator.get_top_Value() == '+' || Operator.get_top_Value() == '-'))
						)
					{
						break;
					}
					cout << "ANS was NOW: " << Postfix << endl;
					cout << "Inserting END in ans:" << Operator.get_top_Value() << endl;
					int char_read = Operator.pop();
					cout << "Char Read is : " << char(char_read) << endl;
					Postfix += char_read;	Postfix += " ";
					cout << "ANS IS NOW: " << Postfix << endl;
				}
				cout << "Left\n";
				Operator.push(Expression[i]);
			}
			if (
				Operator.get_top() == -1
				|| ((Expression[i] == '*' || Expression[i] == '/') && Operator.get_top_Value() == '-')
				|| ((Expression[i] == '*' || Expression[i] == '/') && Operator.get_top_Value() == '+')
				|| ((Expression[i] == '+' || Expression[i] == '*') && Operator.get_top_Value() == '(')
				|| (Expression[i] == '-' && Operator.get_top_Value() == '(')
				|| (Expression[i] == '/' && Operator.get_top_Value() == '(')
				|| (Expression[i] == '^' && Operator.get_top_Value() == '(')
				) {
				cout << "Pushing :: " << Expression[i] << endl;
				Operator.push(Expression[i]);
			}
		}
		cout << "Active::" << Expression[i] << endl;
		cout << "Ans:" << Postfix << endl;
		Operator.Display_Stack();
	}


	while (Operator.get_top() != -1)
	{
		cout << "CLEARING Inserting in ans:" << char(Operator.get_top_Value()) << endl;
		Postfix += Operator.pop();	Postfix += " ";
	}
	cout << "RESULTANT POSTFIX EXPRESSION IS " << Postfix << endl;
	Operator.Display_Stack();
	return Postfix;
}
int main() {
	string Expression;
	Stack<int>obj;
	while (1)
	{
		cout << "Enter expr to check:";
		cin >> Expression;
		infix_To_postfix(Expression);
		_getch();
		system("CLS");
	}
	/*bool ans = balanced_Expression(Expression);
	if (ans)
		cout << "balanced expression" << endl;
	else
		cout << "Unbalanced expression" << endl;*/

}
