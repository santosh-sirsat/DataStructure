#include<iostream>
#include<vector>
// https://leetcode.com/problems/validate-binary-search-tree/

using namespace std;
template<typename T>
class BTNode
{
public:
	T m_data;
	BTNode* m_left;
	BTNode* m_right;

	BTNode(int data)
	{
		m_data = data;
		m_left = nullptr;
		m_right = nullptr;
	}

	~BTNode()
	{
		delete m_left;
		delete m_right;
	}
};


// size()= 4
// 3 + 3
//
BTNode<int>* helper(std::vector<int> nums, int start, int end)
{
	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;
	int rootData = nums[mid];
	
	BTNode<int>* root = new BTNode<int>(rootData);
	root->m_left = helper(nums, start, mid-1);
	root->m_right = helper(nums, mid+1, end);

	return root;
}
//BTNode<int>* sortedArrayToBST(vector<int>& nums, int start, int end) {
//	if (start > end) return NULL;
//	int mid = start + (end - start) / 2;
//	BTNode<int>* node = new BTNode<int>(nums[mid]);
//	node->m_left = sortedArrayToBST(nums, start, mid - 1);
//	node->m_right = sortedArrayToBST(nums, mid + 1, end);
//	return node;
//}

BTNode<int>* sortedArrayToBST(std::vector<int>& nums) 
{
	int n = nums.size() - 1;
	return helper(nums, 0, n);
}

extern void printTree(BTNode<int>* root);

class Base
{
public:
	Base()
	{
		cout << "Base constructor" << endl;
	}
	~Base()
	{
		cout << "~Base() destructor called" << endl;
	}
};
int main()
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	BTNode<int>* root = sortedArrayToBST(nums);
	printTree(root);
	

	/*Base base;
	base.~Base();
	Base* ptr = new Base();

	int x = 10;
	int* mem = new (&x) int();

	char name[100];
	Base* ptrBase = new (&name) Base();*/

	//Base* tw = new Base();
	//delete tw;
	return 0;
}