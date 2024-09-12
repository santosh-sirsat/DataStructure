#include<iostream>
#include<queue>
#include<stack>

using namespace std;
void reverseUsingVector(queue<int>& q)
{
	std::vector<int> v;
	while (!q.empty())
	{
		v.push_back(q.front());
		q.pop();
	}
	//queue is empty
	//iterate the vector from the last
	for (auto itr = v.crbegin(); itr != v.crend(); itr++)
	{
		q.push(*itr);

	}
}
void reverse(queue<int>& q)
{
	stack<int> s;
	while (!q.empty())
	{
		s.push(q.front());
		q.pop();
	}

	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}

}
int main()
{
	queue<int> q;
	for (int index = 1; index <= 5; ++index)
	{
		q.push(index);
	}

	//reverse(q);
	reverseUsingVector(q);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}