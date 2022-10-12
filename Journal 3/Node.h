#pragma once
#include"Student.h"
class Node
{
public:
	Student Student_Data;
	Node* next;
	Node() : next(0) {}
};