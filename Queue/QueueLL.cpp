#include<iostream>
using namespace std;
class Node
{
private:
	int m_data;
	Node* m_next;
public:
	Node(int data) : m_data(data), m_next(nullptr) // ctor with ctor initializer list
	{

	}

	friend class Queue;
};

class Queue
{
private:
	int m_size;
	Node* m_head;
	Node* m_tail;
public:
	Queue()
	{
		m_size = 0;
		m_head = nullptr;
		m_tail = nullptr;
	}
	//deinitialize the Queue;
	~Queue()
	{
		if (!isEmpty())
		{
			while (m_head)
			{
				Node* deleteNode = m_head;
				m_head = m_head->m_next;
				delete deleteNode;
			}
			/*if (m_tail)
			{
				delete m_tail;
			}*/
			m_head = nullptr;
			m_tail = nullptr;
		}
	}
	void push(int data)
	{
		Node *newNode = new Node(data);
		if (isEmpty())
		{
			m_head = newNode;
			m_tail = newNode;
		}
		else
		{
			m_tail->m_next = newNode;
			m_tail = newNode;
		}
		m_size++;
	}
	int front()
	{
		if (m_head)
		{
			return	m_head->m_data;
		}
		else
		{
			return 0;
		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Queue is empty"<<endl;
			return;
		}
		else
		{
			Node* deleteNode = m_head;
			m_head = m_head->m_next;
			m_size--;
			delete deleteNode;
		}
	}
	int getSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		return m_size == 0;
	}
	void print()
	{
		Node* trav = m_head;
		for (int i = 1; i <= m_size; ++i)
		{
			cout << trav->m_data << " ";
			trav = trav->m_next;
		}
		cout << endl;
	}
};
//int main(void)
//{
//	Queue queue;
//	queue.push(10);
//	queue.push(20);
//	queue.push(30);
//	queue.push(40);
//	queue.push(50);
//	queue.push(60);
//
//	queue.print();//10,20,30,40,50,60
//	cout << queue.front() << endl;//10
//	cout << queue.getSize() << endl; // 6
//
//	queue.pop();//10 is deleted
//	cout << queue.front() << endl;//20
//	cout << queue.getSize() << endl; // 5
//	queue.pop();
//	queue.pop();
//	queue.pop();
//	queue.pop();
//	queue.pop();
//	queue.pop();
//
//
//	return 0;
//}