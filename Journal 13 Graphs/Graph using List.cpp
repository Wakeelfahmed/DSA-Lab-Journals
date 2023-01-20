#include<iostream>
using namespace std;
class Node
{
public:
	int dest;
	Node* next;
};
class List
{
public:
	Node* head;
};
class Graph
{
public:
	int V;	//Number of vertices
		List* arr; // An Array of adj lists
		Graph(int V);
	Node* newAdjListNode(int);
	void addEdge(int, int);
	void printGraph();
};
Graph::Graph(int V)
{
	this->V = V;
	arr = new List[V];
	for (int i = 0; i < V; ++i)
		arr[i].head = NULL;
}
Node* Graph::newAdjListNode(int val)
{
	Node* ptr = new Node();
	ptr->dest = val;
	ptr->next = NULL;
	return ptr;
}
void Graph::addEdge(int src, int dest)
{
	Node* temp = newAdjListNode(dest);
	temp->next = arr[src].head;
	arr[src].head = temp;
	/*for undirected graph
	add the following*/
		Node* temp2 = newAdjListNode(src);
	temp2->next = arr[dest].head;
	arr[dest].head = temp2;
}
void Graph::printGraph()
{
	int v;
	for (v = 0; v < V; ++v)
	{
		Node* pCrawl = arr[v].head;
		cout << "\n Adjacency list of vertex " << v << "\n 	head ";
		while (pCrawl != NULL)
		{
			cout << "-> " << pCrawl->dest;
			pCrawl = pCrawl->next;
		}
		cout << endl;
	}
}