#include<iostream>
using namespace std;
void Insetion_Sort(int arr[], int n) {
	cout << "Insetion_Sort\n";
	int temp, i, j;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
		cout << "Pass :" << i << endl;
		for (int k = 0; k < n; k++)
		{
			cout << arr[k] << "\t";
		}cout << endl;
	}
}
template<typename T1>
void seletion_Sort(T1 arr[], int n) {
	cout << "\nSeletion Sort\n";
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(arr[min_idx], arr[i]);
	}
	for (j = 0; j < n; j++)
	{
		cout << arr[j] << "\t";
	}cout << endl;
}
int main() {
	const int n = 7;
	string arr[] = { "Rome", "Oslo", "Bern", "Stockholm", "Barcelona", "Munich", "Paris" };
	for (int k = 0; k < n; k++)
	{
		cout << arr[k] << "\t";
	}cout << endl;
	seletion_Sort(arr, n);
}