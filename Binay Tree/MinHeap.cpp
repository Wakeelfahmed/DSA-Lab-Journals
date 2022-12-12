#include<iostream>
using namespace std;
class MinHeap
{
	int* arr;
	int capacity;
	int heap_size;
public:
	MinHeap(int capacity) {
		heap_size = 0;
		this->capacity = capacity;
		arr = new int[capacity];
	}
	int parent(int i) const { return (i - 1) / 2; }
	int left(int i) const { return (2 * i + 1); }
	int right(int i) const { return (2 * i + 2); }
	int getMin() const { return arr[0]; }
	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	void insertKey(int k) {
		if (heap_size == capacity)
		{
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}
		heap_size++;
		int i = heap_size - 1;
		arr[i] = k;
		while (i != 0 && arr[parent(i)] > arr[i])//Fix the min heap property if violated 
		{
			swap(&arr[i], &arr[parent(i)]);
			i = parent(i);
		}
	}
	int extractMin() {
		if (heap_size == 0) {
			cout << "Heap underflow";	return -1;
		}
		if (heap_size == 1)
		{
			heap_size--;
			return arr[0];
		}
		int root = arr[0];//top element to be returned
		arr[0] = arr[heap_size - 1];//last element goes to top
		heap_size--;
		MinHeapify(0);//Heap Property
		return root;
	}
	void MinHeapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && arr[l] < arr[i])
			smallest = l;
		if (r < heap_size && arr[r] < arr[smallest])
			smallest = r;
		if (smallest != i)
		{
			swap(&arr[i], &arr[smallest]);
			MinHeapify(smallest);
		}
	}
	void decreaseKey(int i, int new_val) {
		arr[i] = new_val;
		while (i != 0 && arr[parent(i)] > arr[i])
		{
			swap(&arr[i], &arr[parent(i)]);
			i = parent(i);
		}
	}
	void deleteKey(int i) {
		decreaseKey(i, INT_MIN);
		extractMin();
	}

};
int main() {
	MinHeap min(5);
	min.left(1);
	cout << "e";
}