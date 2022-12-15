#include<iostream>
using namespace std;
void Print_n_to_0(int n) {
	if (n < 0)		return;
	cout << n << "\t";
	Print_n_to_0(n - 1);
}
bool isPalRec(string str, int s, int e)
{
	// If there is only one character
	if (s == e)
		return true;

	// If first and last
	// characters do not match
	if (str[s] != str[e])
		return false;

	// If there are more than
	// two characters, check if
	// middle substring is also
	// palindrome or not.
	if (s < e + 1)
		return isPalRec(str, s + 1, e - 1);
	return true;
}

bool isPalindrome(string str)
{
	int n = str.length();
	// An empty string is
	// considered as palindrome
	if (n == 0)
		return true;
	return isPalRec(str, 0, n - 1);
}
int binomialCoeff(int n, int k)
{
	// Base Cases
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	// Recur
	return binomialCoeff(n - 1, k - 1)
		+ binomialCoeff(n - 1, k);
}
bool isPrime(int n, int i = 2)
{
	if (n <= 2)
		return (n == 2) ? true : false;
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;
	return isPrime(n, i + 1);
}
int multiply(int array[], int n)
{
	int pro = 1;
	for (int i = 0; i < n; i++)
		pro = pro * array[i];
	return pro;
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	cout << "Array elements are: ";
	int n = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < n; i++)
		cout << array[i] << "\t";
	cout << endl << "Product of the array is:" << multiply(array, n);
}