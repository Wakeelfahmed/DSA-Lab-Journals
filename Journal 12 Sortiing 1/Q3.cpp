#include<iostream>
using namespace std;
int Number_of_Comparisons = 0, Number_of_Swaps = 0;
void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
void Efficient_BubbleSort(int arr[], int length)
{
	cout << "Efficient BubbleSort \n";
	Number_of_Comparisons = 0, Number_of_Swaps = 0;
	int temp, j, pass;
	bool swapped = true;
	for (pass = 0; pass < length - 1 && swapped == true; pass++)
	{
		swapped = false;
		for (j = 0; j < length - pass - 1; j++) {
			Number_of_Comparisons++;
			if (arr[j] > arr[j + 1]) {
				swapped = true;
				Number_of_Swaps++;
				swap(arr[j], arr[j + 1]);
				//temp = S[j];
				//S[j] = S[j + 1];
				//S[j + 1] = temp;
			}
		}
	}
	cout << "Number of Comparisons:" << Number_of_Comparisons << "\tNumber of Swaps:" << Number_of_Swaps << endl;
	for (j = 0; j < length; j++)
	{
		//cout << arr[j] << "\t";
	}cout << endl;
}
void bubbleSort(int arr[], int length) {
	cout << "BubbleSort \n";
	Number_of_Comparisons = 0, Number_of_Swaps = 0;
	int temp, i;
	for (i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++) {
			Number_of_Comparisons++;
			if (arr[j] > arr[j + 1])
			{
				Number_of_Swaps++;
				swap(arr[j], arr[j + 1]);
				//temp = x[j];
				//x[j] = x[j + 1];
				//x[j + 1] = temp;
			}
		}
	}
	cout << "Number of Comparisons:" << Number_of_Comparisons << "\tNumber of Swaps:" << Number_of_Swaps << endl;
	for (int j = 0; j < length; j++)
	{
		//cout << arr[j] << "\t";
	}cout << endl;
}
template<typename T1>
void seletion_Sort(T1 arr[], int n) {
	cout << "\nSeletion Sort\n";
	int i, j, min_idx;
	Number_of_Comparisons = 0, Number_of_Swaps = 0;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			Number_of_Comparisons++;
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if (min_idx != i) {
			swap(arr[min_idx], arr[i]);
			Number_of_Swaps++;
		}
	}
	cout << "Number of Comparisons:" << Number_of_Comparisons << "\tNumber of Swaps:" << Number_of_Swaps << endl;
	for (j = 0; j < n; j++)
	{
		//cout << arr[j] << "\t";
	}//cout << endl;
}
void Insetion_Sort(int arr[], int n) {
	cout << "Insetion_Sort\n";
	Number_of_Comparisons = 0, Number_of_Swaps = 0;
	int temp, i, j;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
			Number_of_Comparisons++;
			arr[j + 1] = arr[j];
			Number_of_Swaps++;
		}
		arr[j + 1] = temp;
	}
	cout << "Number of Comparisons:" << Number_of_Comparisons << "\tNumber of Swaps:" << Number_of_Swaps << endl;
	for (i = 0; i < n; i++)
	{
		//cout << arr[i] << "\t";
	}//cout << endl;
}
int main() {
	const int n = 25000;
	int arr[n];
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
		//cout << arr[i] << "\t";
	}//cout << endl << endl;
	int temp[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	seletion_Sort(temp, n);
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	bubbleSort(temp, n);
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	Efficient_BubbleSort(temp, n);
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	Insetion_Sort(temp, n);
}