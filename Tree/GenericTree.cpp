#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class TreeNode
{
public:
	T m_data;
	std::vector<TreeNode<T>*> m_children;

	TreeNode(T data) 
	{
		m_data = data;
	}
};
void printTree(TreeNode<int>* root)
{
	if (root == nullptr)
		return;

	cout << root->m_data << " : ";
	for (int i = 0; i < root->m_children.size(); i++)
	{
		cout << root->m_children[i]->m_data << " ,";
	}
	cout << endl;

	//call recursion on child nodes;
	for (int i = 0; i < root->m_children.size(); i++)
	{
		printTree(root->m_children[i]);
	}
}

TreeNode<int>* takeInput()
{
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* rootNode = new TreeNode<int>(rootData);

	int n;
	cout << "Enter No.of children for " << rootData << endl;
	cin >> n;

	//accept children data;
	for (int i = 1; i <= n; i++)
	{
		rootNode->m_children.push_back(takeInput());
	}
	return rootNode;

}
//create
//push
//connect
TreeNode<int>* takeInputLevelWise()
{
	//create root node
	int rootData;
	cout << "Enter root element data" << endl;
	cin >> rootData;

	//create node
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> q;
	//push
	q.push(root);

	//connect is not here because it is a root node
	while (!q.empty())
	{
		TreeNode<int>* f = q.front();
		q.pop();

		int n;
		cout << "Enter no of children for " << f->m_data << endl;
		cin >> n;

		//take childrens info
		for (int i = 1; i <= n; i++)
		{
			cout << "Enter " << i << " th childen of a " << f->m_data << endl;
			int data;
			cin >> data;

			//create node;
			TreeNode<int>* child = new TreeNode<int>(data);
			//push//
			q.push(child);
			//connect/
			f->m_children.push_back(child);
		}
	}
	return root;
}
void printTreeLevelOrder(TreeNode<int>* root)
{
	if (root)
	{
		queue<TreeNode<int>*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode<int>* f = q.front();
			q.pop();

			cout << f->m_data << " : ";
			for (int i =0; i < f->m_children.size(); ++i)
			{
				cout << f->m_children[i]->m_data << " ,";
			}
			for (int i = 0; i < f->m_children.size(); i++)
			{
				q.push(f->m_children[i]);
			}
			cout << endl;
		}
	}
	else
	{
		cout << "tree is empty" << endl;
	}
}

int countNode(TreeNode<int>* root)
{
	if (root == nullptr)
		return 0;
	int ans = 1;
	for (int i = 0; i < root->m_children.size(); ++i)
	{
		ans += countNode(root->m_children[i]);
	}
	return ans;
}
int height(TreeNode<int>* root)
{
	int mx = 0;
	for (int i = 0; i < root->m_children.size(); i++)
	{
		mx = std::max(mx, height(root->m_children[i]));
	}
	//mx + 1 for root node.
	return mx + 1;
}
void printAtLevelK(TreeNode<int>* root, int k)
{
	if (root == nullptr)
		return;

	if (k == 0)
	{
		cout<< root->m_data << endl;
	}
	for (int i = 0; i < root->m_children.size(); i++) 
	{
		printAtLevelK(root->m_children[i], k-1);
	}
}
int countLeafNodes(TreeNode<int>* root)
{
	if (root->m_children.size() == 0)
		return 1;

	int ans = 0;
	for (int i = 0; i < root->m_children.size(); ++i)
	{
		ans += countLeafNodes(root->m_children[i]);
	}
	return ans;
}
void preoderTraverser(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->m_data << " ";
	for (int i = 0; i < root->m_children.size(); i++)
	{
		preoderTraverser(root->m_children[i]);
	}
}

void postOrderTraverser(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	for (int i = 0; i < root->m_children.size(); i++)
	{
		postOrderTraverser(root->m_children[i]);
	}
	cout << root->m_data << " ";
}

void deleteTree(TreeNode<int>* root)
{
	if (root == nullptr)
		return;

	for (int i = 0; i < root->m_children.size(); ++i)
	{
		deleteTree(root->m_children[i]);
	}

	delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 
//int main()
//{
//	/*TreeNode<int>* root = new TreeNode<int>(1);
//	TreeNode<int>* node2 = new TreeNode<int>(2);
//	TreeNode<int>* node3 = new TreeNode<int>(3);
//	root->m_children.push_back(node2);
//	root->m_children.push_back(node3);
//	*/
//	//TreeNode<int>* root = takeInput();
//	/*TreeNode<int>* root = takeInputLevelWise();
//	printTree(root);*/
//
//	TreeNode<int>* root = takeInputLevelWise();
//	printTreeLevelOrder(root);
////	cout << "Count of the node is " << countNode(root);
////	cout << "Height of tree is " << height(root);
//	printAtLevelK(root, 2);
//	cout << "Leaf nodes are : " << countLeafNodes(root);
//	//cout << "PreOrder traverser " << endl;
//	//preoderTraverser(root);
//	cout << endl;
//	cout << "Post order traverser" << endl;
//	postOrderTraverser(root);
//	deleteTree(root);
//	return 0;
//}