#include<iostream>
using namespace std;

int const MAX = 10;
class Node
{
public:
	int key;
	Node* next;

	Node() :key(0), next(NULL) {}
	Node(int key) :key(key), next(NULL) {}

};
class Hash
{
public:
	Node* hashtable[MAX];
	Hash() {
		for (int i = 0; i < MAX; i++)
			hashtable[i] = 0;
	}
	int Hash_Fln(int key) {
		return key % MAX;
	}
	void insertkey(int value)
	{
		int key = Hash_Fln(value);
		if (hashtable[key] == NULL)
		{
			Node* p = new Node(value);
			//p->key = value;
			//p->next = NULL;
			hashtable[key] = p;
		}
		else
		{
			Node* p = hashtable[key];
			while (p->next != NULL)
			{
				p = p->next;
			}
			Node* q = new Node;
			q->key = value;
			q->next = NULL;
			p->next = q;
		}
	}
	void display() {
		for (int i = 0; i < MAX; i++) {
			cout << "Elements in Hash Table " << i << ": ";
			Node* p = hashtable[i];
			while (p != NULL) {
				cout << p->key << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
	bool search(int value) {
		int key = Hash_Fln(value);
		Node* p = hashtable[key];
		while (p != NULL) {
			if (p->key == value) {
				return true;
			}
			p = p->next;
		}
		return false;
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
		obj.insertkey(data);
		cout << "Do u want to continue [N/Y]";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	
	obj.display();
	
}
