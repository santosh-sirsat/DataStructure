#include<iostream>
using namespace std;
class Queue
{
	int capacity;
	int nextIndex = 0;
	int firstIndex = -1;
	int* arr;
	int size = 0;
public:
	Queue()
	{
		capacity = 5;
		arr = new int[capacity];
	}
	//0 0 0 0 0
	void push(int data)
	{
		if (size == capacity)
		{
			cout << "queue is full" << endl;
			return;
		}
		nextIndex = (nextIndex - firstIndex + capacity) % capacity;
		arr[nextIndex] = data;
		nextIndex++;
		size++;
	}

	void pop()
	{
		if (isEmpty())
			return;

		firstIndex = ( firstIndex + 1) % capacity;
		size--;
	}
	//get font element
	int front()
	{
		if (isEmpty()) {
			return -1;
		}
		return arr[firstIndex];
	}

	bool isEmpty()
	{
		return size == 0;
	}
};
//int main()
//{
//	Queue queue;
//	queue.push(10);
//	queue.push(20);
//	queue.push(30);
//
//	cout << queue.front();
//	queue.pop();
//	cout << queue.front();
//	queue.pop();
//	cout << queue.front();
//	queue.pop();
//	return 0;
//}