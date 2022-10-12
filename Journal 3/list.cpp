#include"list.h" 
using namespace std;
list::list() : head(NULL), tail(NULL) {}
Node* list::get_head() const { return head; }
Node* list::get_tail() const { return tail; }
bool list::isEmpty() {
	if (head == NULL)
		return true;
	return false;
}
void list::insert_beg(Student student) {
	Node* p = new Node;
	p->Student_Data = student;
	if (isEmpty())
		tail = p;
	else
		p->next = head;
	head = p;
}
void list::insert_specfic_Position(int Position, Student student) {
	int position_count = 1;
	if (Position > Number_of_Nodes()) {
		cout << "List has less nodes than the place, Node CAN't be inserted!!\n";
		return;
	}
	Node* NewNode = new Node;
	NewNode->Student_Data = student;
	Node* p = head;
	while (p != NULL)
	{
		if (Position == 1) {
			insert_beg(student);
			return;
		}
		else if (Position == Number_of_Nodes()) {
			insert_end(student);
			return;
		}
		else if (position_count == Position - 1 && Position != 0) {
			NewNode->next = p->next;
			p->next = NewNode;
			return;
		}
		p = p->next;		//move to next node
		position_count++;
	}
}
void list::insert_after(Student oldvalue, Student newvalue) {
	if (isEmpty())
	{
		cout << "List is empty";
		return;
	}
	Node* p = head;
	int position_count = 1;
	while (p != NULL)
	{
		if (p->Student_Data.get_enrollment() == oldvalue.get_enrollment() || p->Student_Data.get_name() == oldvalue.get_name())
		{
			Node* NewNode = new Node;
			NewNode->Student_Data = newvalue;
			if (position_count == Number_of_Nodes()) {
				p->next = NewNode;
				tail = NewNode;
				//insert_end(newvalue);
			}
			else
			{
				NewNode->next = p->next;
				p->next = NewNode;
				//insert_specfic_Position(position_count, newvalue);
			}
			return;
		}
		p = p->next;
		position_count++;
	}
}
void list::insert_end(Student student) {
	Node* p = new Node;
	p->Student_Data = student;
	if (isEmpty())
	{
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}
void list::Display_list() {
	if (isEmpty())
	{
		cout << "list is empty!!" << endl;
		return;
	}
	Node* p = head;
	cout << "List: " << endl;
	while (p != NULL)
	{
		cout << "name:" << p->Student_Data.get_name()
			<< "\tenrollment:" << p->Student_Data.get_enrollment() << endl;
		p = p->next;
	}
	cout << endl;
}
int list::Number_of_Nodes() {
	if (isEmpty())
	{
		cout << "list is empty!! \n there are no nodes." << endl;
		return 0;
	}
	int Counter = 0;
	Node* p = head;
	while (p != NULL)
	{
		Counter++;
		p = p->next;
	}
	return Counter;
}