#include<iostream>
#include<stack>

using namespace std;
bool BalanceParanthesis(std::string str)
{
	bool result = true;
	std::stack<char> charStack;

	//iterating the string
	for (int index = 0; index < str.size(); index++)
	{
		//1 if opening paranthesis found then push in to the charStack
		if (str[index] == '(' || str[index] == '{' || str[index] == '[')
		{
			charStack.push(str[index]);
		}
		else // its a closing parantesis
		{
			if (charStack.empty()) return false;

			if (str[index] == ')' && charStack.top() == '(')
			{
				charStack.pop();
			}
			else if (str[index] == '}' && charStack.top() == '{')
			{
				charStack.pop();
			}
			else if (str[index] == ']' && charStack.top() == '[')
			{
				charStack.pop();
			}
			else
				return false;
		}
		
		//2 if closing paranthesis found then top of the element in the charStack check with current element and which is closing openring paranthesis or not.
		
	}
	if (!charStack.empty())
	{
		result = false;
	}
	return result;
}
int main()
{
	std::string st = "({{{(}}})";
	if (BalanceParanthesis(st))
	{
		cout << "Balanced " << endl;
	}
	else
	{
		cout << "Not balanced" << endl;
	}
}