#include<iostream>
using namespace std;
void merge(int*, int*, int, int, int);
void mergesort(int* a, int* b, int low, int high) {
	int pivot;
	if (low < high) {
		pivot = (low + high) / 2;
		mergesort(a, b, low, pivot);
		mergesort(a, b, pivot + 1, high);
		merge(a, b, low, pivot, high);
	}
}
//void merge(int*, int*, int, int, int)
void merge(int* a, int* b, int low, int pivot, int high)
{
	int h, i, j, k;
	h = low;
	i = low;
	j = pivot + 1;

	while ((h <= pivot) && (j <= high))
	{
		if (a[h] <= a[j]) {
			b[i] = a[h];
			h++;
		}
		else {
			b[i] = a[j];
			j++;
		}
		i++;
	}

	if (h > pivot) //Second sub - list has elements left
	{
		for (k = j; k <= high; k++) {
			b[i] = a[k];
			i++;
		}
	}
	else //First sub - list has elements left
	{
		for (k = h; k <= pivot; k++) {
			b[i] = a[k];
			i++;
		}
	}
	//Copy all elements of ‘b’ into ‘a’
	for (k = low; k <= high; k++)
		a[k] = b[k];
}
void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
int Split(int x[], int low, int high)
{
	int pivot = x[low];
	int left = low;
	int right = high;
	while (left < right)
	{
		while (x[right] > pivot)
			right--;
		while (x[left] <= pivot && left < right)
			left++;
		if (left < right)
			swap(x[left], x[right]);
	}
	swap(x[low], x[right]);
	return right;
}
void QuickSort(int x[], int low, int high)
{
	if (low < high)	//List has more than one element.
	{
		int pi = Split(x, low, high);
		//Split(x, low, high, pos);	// Split into two sublists.
		QuickSort(x, low, pi - 1);	// Sort the left sublist.
		QuickSort(x, pi + 1, high);	// Sort the right sublist.
	}
	// else list has 0 or 1 element and requires no sorting
}
//int shellSort(int arr[], int n)
//{
//	// Start with a big gap, then reduce the gap
//	for (int gap = n / 2; gap > 0; gap /= 2)
//	{
//		// Do a gapped insertion sort for this gap size.
//		// The first gap elements a[0..gap-1] are already in gapped order
//		// keep adding one more element until the entire array is
//		// gap sorted 
//		for (int i = gap; i < n; i += 1)
//		{
//			// add a[i] to the elements that have been gap sorted
//			// save a[i] in temp and make a hole at position i
//			int temp = arr[i];
//
//			// shift earlier gap-sorted elements up until the correct 
//			// location for a[i] is found
//			int j;
//			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//				arr[j] = arr[j - gap];
//
//			//  put temp (the original a[i]) in its correct location
//			arr[j] = temp;
//		}
//	}
//	return 0;
//}
void shellsort(int x[], int n, int incrmnts[], int numincr)
{
	int span, y;

	for (int incr = 0; incr < numincr; incr++)
	{
		/*Span is the size of increment*/
		span = incrmnts[incr];

		for (int j = span; j < n; j++)
		{
			/*Insert x[j] at its proper location within its subfile
			  using simple insert sort*/
			y = x[j];
			int k;
			for (k = j - span; k >= 0 && y < x[k]; k -= span)
				x[k + span] = x[k];
			x[k] = y;
		}
	}
}
int main() {
	const int num = 8;

	int a[] = { 12,10,43,23,78,45,56,98 };
	int n = sizeof(a) / sizeof(a[0]);
	int gap[] = { 5, 3, 1 };
	int numincr = sizeof(gap) / sizeof(gap[0]);
	int b[num];
	//mergesort(a, b, 0, num - 1);
	//QuickSort(a, 0, num - 1);
	shellsort(a, n, gap, numincr);
	for (int i = 0; i < num; i++)
			cout << a[i] << " "; cout << endl;

}

//while (left < right)
//	if (a[left] <= a[pivot])
//		left++;
//	else if (right > a[pivot])
//		right--;
//	else
//		swap(a[left], a[right]);
//}
//	swap(a[right], pivot);