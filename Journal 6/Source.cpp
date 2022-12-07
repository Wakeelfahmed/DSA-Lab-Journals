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
		cout << "Enter Positive Number";
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
		if (obj.get_top() == -1)
			obj.push(Expression[i]);
		else if ((obj.get_top_Value() == '(' && Expression[i] == ')') || (obj.get_top_Value() == '[' && Expression[i] == ']'))
			obj.pop();
		else
			obj.push(Expression[i]);
	}
	if (obj.get_top() == -1)
		return 1;
	else
		return 0;
}
int Get_Precendence(char elem)
{
	switch (elem)
	{
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	case '^': return 4;
	}
}
string infix_To_postfix(string Expression) {
	Stack<char> Operator;	string Postfix;
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
		else if (Expression[i] == ')') {
			while (Operator.get_top_Value() != '(')
				Postfix = (Postfix + Operator.pop() + " ");
			Operator.pop();
		}
		else if (Expression[i] == '(')
			Operator.push('(');
		else {
			while (Get_Precendence(Operator.get_top_Value()) >= Get_Precendence(Expression[i])
				&& !(Expression[i] == '^' && Operator.get_top_Value() == '^'))
				Postfix = Postfix + Operator.pop() + " ";
			Operator.push(Expression[i]);
		}
	}
	while (Operator.get_top() != -1)
		Postfix = Postfix + Operator.pop() + " ";
	cout << "RESULTANT POSTFIX : " << Postfix << endl;
	return Postfix;
}
int mystery(int n, int k) {
	if (n == 0)
		return 0;
	else
	{
		int x = (mystery(n - 1, k) + k) % n;
		cout << x << endl;
		return x;
	}
}
int main() {
	string Expression;
	cout << "Final ans:" << mystery(4, 2) << endl;
	while (1)
	{
		cout << "Enter expr to check:";		cin >> Expression;
		infix_To_postfix(Expression);		_getch();		system("CLS");
	}
}