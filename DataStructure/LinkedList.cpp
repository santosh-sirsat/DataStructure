#include<iostream>
using namespace std;

class Node
{
public:

	int m_data;
	Node* m_next;

public:
	Node(int data) : m_data(data), m_next(nullptr)
	{

	}


};

void Print(Node* head)
{
	while (head != nullptr)
	{
		cout << head->m_data << "->";
		head = head->m_next;

	}
	cout << "NULL" << endl;
}
//
//int main(void)
//{
//	Node n1(10);
//	
//	Node n2(20);
//	Node n3(30);
//	Node n4(40);
//
//	//create head;
//
//	Node* head = nullptr;
//	head = &n1;
//
//	n1.m_next = &n2;
//	n2.m_next = &n3;
//	n3.m_next = &n4;
//
//	//print linked list data
//	Print(head);
//
//	return 0;
//}