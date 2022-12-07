#include <iostream>
#include <conio.h>
using namespace std;
const int Size = 3;
class queue
{
private:
	int arr[Size];
	int front, rear, count;
public:
	queue() { front = rear = count = 0; }
	void enqueue(int data)
	{
		if (count != Size)
			cout << "Queue is Full..." << endl;
		else
		{
			arr[rear] = data;
			rear = (rear + 1) % Size;
			count++;
		}
	}
	int dequeue()
	{
		if (count == 0)
			cout << "Queue is empty..." << endl;
		else
		{
			count--;
			int temp = arr[front];
			front = (front + 1) % Size;
			return temp;
		}
	}
};
int main()
{
	queue q;
	cout << "Enqueuing:"; q.enqueue(45); cout << endl;
	cout << "Enqueuing:"; q.enqueue(55); cout << endl;
	cout << "Enqueuing:"; q.enqueue(5); cout << endl;
	cout << "Enqueuing:"; q.enqueue(57); cout << endl;
	cout << "The Element is: " << q.dequeue() << endl;
	cout << "The Element is: " << q.dequeue() << endl;
	cout << "The Element is: " << q.dequeue() << endl;
	cout << "The Element is: " << q.dequeue() << endl;
	cout << "The Element is: " << q.dequeue() << endl;
	_getch();

}