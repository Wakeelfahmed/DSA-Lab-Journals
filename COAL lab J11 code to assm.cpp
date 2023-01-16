#include<iostream>
using namespace std;
int main() {
	int y;
	int temp;
	//std::cin >> y;
	for (int y = 0; y < 10; y++)
	{
		temp = y;
		//std::cout << "C++ Enter #: ";
		cout << "input y is " << y << endl;
		for (int i = 0; i <= 5; i++)
		{
			if (i <= 3) { y = y + 2; }
			if (y == 5) { y = y + 4; }
		}
		cout << "ANS:" << y << endl;
		y = temp;
	}
}