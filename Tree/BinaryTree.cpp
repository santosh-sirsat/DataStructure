#include<iostream>
#include<queue>
#include<vector>

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

void printTree(BTNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->m_data << " : ";
	if (root->m_left != nullptr)
	{
		cout << "L" << root->m_left->m_data;
	}
	if (root->m_right != nullptr)
	{
		cout << "R" << root->m_right->m_data;
	}
	cout << endl;
	printTree(root->m_left);
	printTree(root->m_right);
}
BTNode<int>* takeInput()
{
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;

	if (rootData == -1)
		return nullptr;

	BTNode<int>* root = new BTNode<int>(rootData);
	BTNode<int>* leftChildren = takeInput();
	BTNode<int>* rightChildren = takeInput();
	root->m_left = leftChildren;
	root->m_right = rightChildren;
	return root;
}
//create node
//push node into the queue
// do link
BTNode<int>* takeInputLevelWise()
{
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1)
	{
		return nullptr;
	}

	BTNode<int>* root = new BTNode<int>(rootData);
	std::queue<BTNode<int>*> q;
	q.push(root);

	while (!q.empty())
	{
		BTNode<int>* f = q.front();
		q.pop();

		//ask the left child data
		int leftChildData;
		cout << "Enter left child data of " << f->m_data << endl;
		cin >> leftChildData;

		if (leftChildData != -1)
		{
			BTNode<int>* leftChild = new BTNode<int>(leftChildData);
			f->m_left = leftChild;
			q.push(leftChild);
		}

		//ask for the right child data

		int rightChildData;
		cout << "Enter right child data of " << f->m_data << endl;
		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BTNode<int>* rightChild = new BTNode<int>(rightChildData);
			f->m_right = rightChild;
			q.push(rightChild);
		}
	}
	return root;
}
vector<vector<int>> levelOrder(BTNode<int>* root)
{
	vector<vector<int>> v;
	if (root == nullptr)
	{
		return v;
	}
	vector<int> temp;//storing is storing result of current level.
	
	queue<BTNode<int>*> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty())
	{
		BTNode<int>* f = q.front();
		q.pop();

		if (f == nullptr)
		{
			v.push_back(temp);
			temp.clear();
			if (!q.empty())
			{
				q.push(nullptr);
			}
		}
		else
		{
			temp.push_back(f->m_data);
			if (f->m_left)
			{
				q.push(f->m_left);
			}
			if (f->m_right)
			{
				q.push(f->m_right);
			}
		}
	}
	return v;
}
int countNode(BTNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return countNode(root->m_left) + countNode(root->m_right) + 1;
}

//inorder traverser
void inorder(BTNode<int>* root)
{

}
int height(BTNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int left = height(root->m_left);
	int right = height(root->m_right);
	return max(left, right) + 1;
}

bool helper(BTNode<int>* leftTree, BTNode<int>* rightTree)
{
	if (leftTree == nullptr && rightTree != nullptr) return false;
	if (rightTree == nullptr && leftTree != nullptr) return false;
	if (leftTree == nullptr && rightTree == nullptr) return true;
	if (leftTree->m_data != rightTree->m_data) return false;
	 
	return helper(leftTree->m_left, rightTree->m_right) 
		&& helper(leftTree->m_right, rightTree->m_left);
}

bool isSymentric(BTNode<int>* root)
{
	if (root == nullptr) 
		return true;

	return helper(root->m_left, root->m_right);

}

bool search(BTNode<int>* root, int element)
{
	if (root == nullptr) return false;
	if (root->m_data == element) return true;
	return (search(root->m_left, element) || search(root->m_right, element));
}

int minValue(BTNode<int>* root)
{
	int min = 0;
	if (root == nullptr)
		return 0;

	min = std::min(minValue(root->m_left), minValue(root->m_right));

	return std::min(min, root->m_data);
}

int maxValue(BTNode<int>* root)
{
	int mx = 0;
	if (root == nullptr)
	{
		return 0;
	}
	mx = std::max(maxValue(root->m_left), maxValue(root->m_right));
	return std::max(mx, root->m_data);
}

int leafNode(BTNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root->m_left == nullptr && root->m_right == nullptr)
		return 1;
	
	return  leafNode(root->m_left) + leafNode(root->m_right);
}

BTNode<int>* Search(BTNode<int>* root, int element)
{
	if (root == nullptr)
		return nullptr;
	if (root->m_data == element)
		return root;

	if (element > root->m_data)
	{
		return Search(root->m_right, element);
	}
	else if (element < root->m_data)
	{
		return Search(root->m_left, element);
	}
	return nullptr;
}
int minBST(BTNode<int>* root)
{
	if (root == nullptr)
		return -1;
	while (root->m_left != nullptr)
	{
		root = root->m_left;
	}
	return root->m_data;
}
int minBSTRecursive(BTNode<int>* root)
{
	if (root == nullptr)
		return -1;

	if (root->m_left != nullptr)
		return minBSTRecursive(root->m_left);
	else
		return root->m_data;
}
int maxBST(BTNode<int>* root)
{
	if (root == nullptr)
		return -1;
	while (root->m_right != nullptr)
	{
		root = root->m_right;
	}
	return root->m_data;
}

int maxBSTRecursiveMethod(BTNode<int>* root)
{
	if (root == nullptr)
		return -1;

	if (root->m_right != nullptr)
		return maxBST(root->m_right);
	else
		return root->m_data;
}
int rangeSum(BTNode<int>* root, int L, int R)
{
	//base case
	if (root == nullptr)
		return 0;

	int sum = 0;
	if (root->m_data >= L && root->m_data <= R)
	{
		sum += root->m_data;
	}
	
	if (root->m_data > R)
	{
		sum += rangeSum(root->m_left, L, R);
	}
	else if (root->m_data < L)
	{
		sum += rangeSum(root->m_right, L, R);
	}
	else
	{
		sum += rangeSum(root->m_right, L, R) + rangeSum(root->m_left, L, R);
	}
	return sum;
}

bool isBinaryTree(BTNode<int>* root, long long min = -10000000000, long long max = 10000000000)
{
	if (root == nullptr) return true;

	bool leftTree = isBinaryTree(root->m_left, min, root->m_data);
	bool rightTree = isBinaryTree(root->m_right, root->m_data, max);

	if (leftTree && rightTree && root->m_data > min && root->m_data < max)
		return true;
	else
		return false;
}
// letf data of the binary root node data is always less and 
bool IsBinarySearchTree(BTNode<int>* root)
{
	return isBinaryTree(root);
}

//int main(int argc, char* argv)
//{
//	BTNode<int>* root = takeInputLevelWise();
//	printTree(root);
//
//	if (IsBinarySearchTree(root))
//		cout << "Given tree is binary search tree" << endl;
//	else
//		cout << "Not a binary search tree" << endl;
//	delete root;//this will delete whole tree.
//
//	return 0;
//}

// 5 3 8 2 4 7 9 -1 -1 -1 -1 -1 -1 -1 -1
// 10 5 15 3 7 -1 18 -1 -1 -1 -1 -1 -1