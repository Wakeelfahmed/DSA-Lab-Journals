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
int Ackermann(int m, int n)
{
	if (m == 0)   return   n + 1;
	else  if (m > 0 && n == 0)   return  Ackermann(m - 1, 1);
	else  if (m > 0 && n > 0)
		return   Ackermann(m - 1, Ackermann(m, n - 1));
}

int main()
{
	cout << Ackermann(3, 4);
}