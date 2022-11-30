#include<iostream>
#include<conio.h>
using namespace std;
class stack
{
private:
	int arr[5];
	int top;
public:
	stack() : top(-1) {}
	void push(int v) {
		if (top == 5 - 1) {
			cout << "OverFlow\n";  return;
		}
		arr[++top] = v;
	}
	int pop() {
		if (top == -1) {
			cout << "Underflow"; return;
		}
		return arr[top--];
	}
};
int main() {
	cout << "He";
	stack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	cout << "Value is " << obj.pop() << endl;
	cout << "Value is " << obj.pop() << endl;
}