#include<iostream>
using namespace std;

class Stack
{
private:
	int* m_arr;
	int m_nextIndex;
	int m_capacity;
public:
	Stack() : m_capacity(10)
	{
		m_arr = new int[m_capacity];
		m_nextIndex = 0;
	}

	Stack(int size) : m_nextIndex(0), m_capacity(size)
	{
		m_arr = new int[size];
	}

	void Push(int data)
	{
		if (m_nextIndex == m_capacity)
		{
			int* newArr = new int[m_capacity * 2];
			//copy the elements
			for (int i = 0; i <= m_capacity; ++i)
			{
				newArr[i] = m_arr[i];
			}
			delete[] m_arr;

			m_arr = newArr;
			m_capacity *= 2;
		}

		m_arr[m_nextIndex] = data;
		m_nextIndex++;
	}
	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is underflow!" << endl;
			return;
		}

		m_nextIndex--;

	}
	int Top()
	{
		if (IsEmpty())
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return m_arr[m_nextIndex -1];
	}
	int Size()
	{
		return m_nextIndex;
	}
	bool IsEmpty()const
	{
		return m_nextIndex == 0;
	}
	void Print()const
	{
		if (IsEmpty())
		{
			cout << "stack is underflow" << endl;
			return;
		}
		for (int i = m_nextIndex; i >=0; --i)
		{
			cout << " " << m_arr[i];
		}
	}
};

int main()
{
	cout << "Welcome to stack demo" << endl;
	Stack stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	cout << stack.Top() << endl;
	stack.Pop();
	cout << stack.Top() << endl;
	stack.Pop();
	cout << stack.Top() << endl;
	stack.Pop();

	cout << "size of the stack is " << stack.Size() << endl;
	cout << "is empty:" << stack.IsEmpty() << endl;
	
}