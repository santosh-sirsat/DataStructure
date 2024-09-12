#include<iostream>
using namespace std;

template<typename T>
class Node
{
	T data;
	Node<T>* next;
public:
	Node(T data)
	{
		this->data = data;
		this->next = nullptr;
	}
	template<typename t>
	friend class Stack;
};

template<typename T>
class Stack
{
	Node<T>* head;
	int size;
public:
	Stack()
	{
		size = 0;
		head = nullptr;
	}
	void Push(T data) 
	{
		Node<T> *node = new Node<T>(data);
		if (IsEmpty())
		{
			head = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
		size++;
	}
	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is underflow!"<<endl;
			return;
		}
		else
		{
			Node<T>* deleteNode = head;
			head = head->next;
			delete deleteNode;
		}
		size--;
	}
	T Top()
	{
		if (IsEmpty())
		{
			cout << "Stack is underflow" << endl;
			return 0;
		}
		else
		{
			return head->data;
		}
	}
	int GetSize()
	{
		return size;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	
};

//int main()
//{
//	Stack<char> st;
//	st.Push(100);
//	st.Push(101);
//	st.Push(102);
//	st.Push(103);
//	st.Push(104);
//	
//	cout << " " << st.Top() << endl;
//	st.Pop();
//	cout << " " << st.Top() << endl;
//	st.Pop();
//	cout << " " << st.Top() << endl;
//	st.Pop();
//
//	cout << "size " << st.GetSize() << endl;
//	cout << "IsEmpty : " << st.IsEmpty() << endl;
//	return 0;
//}