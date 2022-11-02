#pragma once
#include"Employee.h"
class Node
{
public:
	Node* prev;
	Employee data;
	Node* next;
	Node();
	Node(Employee Data);
};