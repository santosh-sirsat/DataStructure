#include<iostream>
using namespace std;
class Node
{
public:
	int m_data;
	Node* m_next;
	Node(int data)
	{
		m_data = data;
		m_next = nullptr;
	}

	~Node()
	{
		if (m_next)
		{
			delete m_next;
		}
		cout << "I am die"<<endl;
	}

};

void PrintLinkedList(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		cout << temp->m_data << "->";
		temp = temp->m_next;
	}
	cout << "NULL"<<endl;
}
Node* takeInput()
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int data;
	cin >> data;

	while (data != -1)
	{
		Node* newNode = new Node(data);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->m_next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

Node* takeInput2()
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int data;
	cin >> data;

	while (data != -1)
	{
		Node* newNode = new Node(data);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->m_next = head;
			head = newNode;
		}
		cin >> data;
	}
	return head;
}


void FreeLinkedList(Node* head)
{
	Node* trav = head;
	while (trav != nullptr)
	{
		Node* tmp = trav;
		trav = trav->m_next;
		delete tmp;
	}
}
int LengthOfLinkedList(Node* head)
{
	Node* trav = head;
	int length = 0;
	while (trav != nullptr)
	{
		length++;
		trav = trav->m_next;
	}
	return length;
}
void PrintIthNode(Node* head, int i)
{
	int index = 0;
	while (head)
	{
		if (i == index)
			break;

		index++;
		head = head->m_next;
	}
	if (i == index)
	{
		cout << "data : " << head->m_data;
	}
	else
	{
		cout << "Node not present" << endl;
	}
}
Node* InsertAtIthPosition(Node* head, int index, int data)
{
	if (index < 0)
		return head;

	if (index == 0)//first locations
	{
		Node* newNode = new Node(data);
		newNode->m_next = head;
		head = newNode;
		return head;
	}

	int counter = 1;
	Node* trav = head;
	while (counter < index - 1 && trav)
	{
		trav = trav->m_next;
		counter++;
	}

	if (trav)
	{
		Node* newNode = new Node(data);

		newNode->m_next = trav->m_next;
		trav->m_next = newNode;
		return head;
	}
}
Node* DeleteIthNode(Node* head, int index);
Node* DeleteIthNode(Node* head, int index)
{
	if (index < 0)
	{
		cout << "Invalid  index " << endl;
		return head;
	}

	if (index == 0 && head)//first node
	{
		Node* newHead = head->m_next;
		
		head->m_next = nullptr;
		delete head;

		return newHead;
	}

	int counter = 1;
	Node* curr = head;
	while (counter < index - 1 && curr)
	{
		curr = curr->m_next;
		counter++;
	}

	if (curr && curr->m_next)
	{
		Node* deletionNode = curr->m_next;
		
		curr->m_next = deletionNode->m_next;
		deletionNode->m_next = nullptr;
		delete deletionNode;
		
		return head;
	}
	else
	{
		cout << "Invalid index" << endl;
		return head;
	}
	// go the ith idex -1 node 
	// then temp pointer to point the ith -1 node next 
	// then change the ith-1 node next to temp->next;
	//now delete temp
	// and return the head;

}
// curr 2 next 3 and prev 1 
// secure next node 
// curr->next = prev
// prev = curr
//1 2 3 4 5
Node* ReverseLinkedList(Node* head)
{
	Node* prev = nullptr;
	Node* curr = head;

	while (curr != nullptr)
	{
		Node* next = curr->m_next;

		curr->m_next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* MiddleNode(Node* head)
{
	Node* slow = head;
	Node* fast = head->m_next;

	while (fast && fast->m_next)
	{
		slow = slow->m_next;
		fast = fast->m_next->m_next;
	}
	Node* middleNode = nullptr;
	if (fast)//even
	{
		middleNode = slow->m_next;
	}
	else
	{
		middleNode =slow;
	}
	return middleNode;
}

Node* RemoveKthNodeFromLast(Node* head, int k)
{
	// create two pointer first, two 
	// initially both pointing to head
	// then make a kth jump for two point
	// then move both pointer to one step till two->next != null;

	Node* first = head;
	Node* second = head;

	//step 2 just kth node for second pointer
	while (k--)
	{
		second = second->m_next;
	}

	if (second->m_next == nullptr)
	{
		return first->m_next;
	}

	while (second->m_next)
	{
		first = first->m_next;
		second = second->m_next;
	}

	//make a link
	first->m_next = first->m_next->m_next;
	
	return head;
}

Node* MergeTwoSortedLinkedList(Node* l1, Node* l2)
{
	Node* finalHead = nullptr;
	if (l1 == nullptr)
	{
		return l2;
	}
	if (l2 == nullptr)
	{
		return l1;
	}

	//set head node
	if (l1->m_data < l2->m_data)
	{
		finalHead = l1;
		l1 = l1->m_next;
	}
	else
	{
		finalHead = l2;
		l2 = l2->m_next;
	}

	Node* p = finalHead;
	//loop the element when both the list is not null
	while (l1 && l2)
	{
		if (l1->m_data < l2->m_data)
		{
			p->m_next = l1;
			l1 = l1->m_next;
			p = p->m_next;
		}
		else
		{
			p->m_next = l2;
			l2 = l2->m_next;
			p = p->m_next;
		}
	}

	if (l1)
	{
		p->m_next = l1;
	}
	if (l2)
	{
		p->m_next = l2;
	}
	return finalHead;
}

int main()
{
	//	Node* head = takeInput(); // insert element at tail (last);
	//Node* head = takeInput(); // insert element at head(first);
	//PrintLinkedList(head);
	//cout << "Length of linked list is " << LengthOfLinkedList(head);
	//PrintIthNode(head, 2);
	//FreeLinkedList(head);
	/*int data, index;
	cout << "insert index" << endl;
	cin >> index;
	cout << "insert data" << endl;
	cin >> data;
	head = InsertAtIthPosition(head, index, data);*/
//	int index;
//	cin >> index;
//	head = DeleteIthNode(head, index);
//	cout << "Middle Node data -> " << MiddleNode(head)->m_data << endl;
	//head = ReverseLinkedList(head);
	//int k;
//	cout << "Enter kth node number" << endl;
//	cin >> k;
//	head = RemoveKthNodeFromLast(head, k);
//	PrintLinkedList(head);

	Node* l1 = takeInput();
	Node* l2 = takeInput();
	Node* mergell;
	mergell = MergeTwoSortedLinkedList(l1, l2);
	cout << "First linked list " << endl;
	PrintLinkedList(l1);
	cout << "Second linked list" << endl;
	PrintLinkedList(l2);
	cout << "Sorted linked list " << endl;
	PrintLinkedList(mergell);
	return 0;
};

