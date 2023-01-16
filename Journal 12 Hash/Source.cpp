#include<iostream>
using namespace std;

int const MAX = 10;
class Hash
{
public:
	int Hashtable[MAX];
	Hash() {
		for (int i = 0; i < MAX; i++)
			Hashtable[i] = 0;
	}int Hash_Fln(int key) {
		return key % MAX;
	}
	void linear_Probing(int HashTable[], int value) {
		int key = Hash_Fln(value);
		if (HashTable[key] == 0)
			HashTable[key] = value;
		else
			while (true)
			{
				key++;
				if (HashTable[key] == 0) {
					HashTable[key] = value;
					break;
				}
			}
	}
	void linear_Probing(int HashTable[], int value) {
		int key = Hash_Fln(value);
		if (HashTable[key] == 0)
			HashTable[key] = value;
		else
			while (true)
			{
				key++;
				if (HashTable[key] == 0) {
					HashTable[key] = value;
					break;
				}
			}
	}
};


int main() {

	Hash obj;
	int hashTable[MAX], data;
	char ch;
	do
	{
		cout << "enter value";
		cin >> data;
		obj.linear_Probing(hashTable, data);
		cout << "Do u want to continue [N/Y]";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	//print the hash
	//search a particular value
}
