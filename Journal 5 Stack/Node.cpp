#include"Node.h"
#include<iostream>
using namespace std;
Node::Node() : next(0), prev(0) {}
Node::Node(Employee Data) :prev(0), data(Data), next(0) {}