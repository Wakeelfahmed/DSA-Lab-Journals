#include<iostream>
#include<ctime>
using namespace std;
//void shellsort(int x[], int n, int incrmnts[], int numincr)
//{
//    int span, y;
//
//    for (int incr = 0; incr < numincr; incr++)
//    {
//        /*Span is the size of increment*/
//        span = incrmnts[incr];
//
//        for (int j = span; j < n; j++)
//        {
//            /*Insert x[j] at its proper location within its subfile
//            using simple insert sort*/
//            y = x[j];
//            int k;
//            for (k = j - span; k >= 0 && y < x[k]; k -= span)
//                x[k + span] = x[k];
//            x[k] = y;
//        }
//    }
//}
void shellSort(int arr[], int n, int gap, int& comparisons, int& shifts)
{
	for (int i = gap; i < n; i += 1)
	{
		int temp = arr[i];
		int j;
		for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
		{
			arr[j] = arr[j - gap];
			comparisons++;
			shifts++;
		}
		arr[j] = temp;
		shifts++;
	}
}
int* get_Duplicate_Array(int arr[], int length) {
	int* temp = new int[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = arr[i];
	}
	return temp;
}
int main()
{
	srand(time(0));
	const int n = 1000;
	int arr[n], comparisons = 0, shifts = 0;
	int gaps1[] = { 25, 10, 5, 1 };	int gaps2[] = { 100, 50, 25, 10, 1 };
	int gaps3[] = { 5, 3, 1 };
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 1000;
		//cout << arr[i] << "\t";
	}cout << endl;
	cout << "Using Gap 1: { 25, 10, 5, 1 }" << endl;
	int* temp_array = get_Duplicate_Array(arr, n);
	for (int i = 0; i < sizeof(gaps1) / sizeof(gaps1[0]); i++)
	{
		shellSort(temp_array, n, gaps1[i], comparisons, shifts);
	}
	cout << "Number of comparisons : " << comparisons << endl;
	cout << "Number of shifts : " << shifts << endl;
	cout << "Time Taken : " << comparisons + shifts << endl;
	cout << "\nUsing Gap 2 { 100, 50, 25, 10, 1 }" << endl;
	comparisons = 0, shifts = 0;
	temp_array = get_Duplicate_Array(arr, n);
	for (int i = 0; i < sizeof(gaps2) / sizeof(gaps2[0]); i++)
	{
		shellSort(temp_array, n, gaps2[i], comparisons, shifts);
	}
	cout << "Number of comparisons : " << comparisons << endl;
	cout << "Number of shifts : " << shifts << endl;
	cout << "Time Taken : " << comparisons + shifts << endl;
	cout << "\nUsing Gap 3 { 5, 3, 1 }" << endl;
	comparisons = 0, shifts = 0;
	temp_array = get_Duplicate_Array(arr, n);
	for (int i = 0; i < sizeof(gaps3) / sizeof(gaps3[0]); i++)
	{
		shellSort(temp_array, n, gaps3[i], comparisons, shifts);
	}
	cout << "Number of comparisons : " << comparisons << endl;
	cout << "Number of shifts : " << shifts << endl;
	cout << "Time Taken : " << comparisons + shifts << endl;
}