#include"Node.h"
#include<iostream>
using namespace std;
Node::Node() : next(0) , Data(0) {}
Node::Node(char Data) : Data(Data) ,next(0) {}