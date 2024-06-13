#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;
	
	//constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	} 
};

class BinaryTree
{
public:
	Node* ROOT;
	  
	BinaryTree()
	{
		ROOT = nullptr; //initializing root to null
	}

	void insert(string element) // insert a node in the binaru search tree
	{
		Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for the new node
		newNode->info = element; // assign value ti data field of the new node
		newNode->leftchild = nullptr; // make the left child of the new node point to null
		newNode->rightchild = nullptr; // make right child of the new node point to null

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); // locate the new node which will be the parent of the node to be insert

		if (parent == nullptr) // if the parent is null (tree is empety)
		{
			ROOT = newNode; // mark the new node as root
			return; //exit
		}

		if (element < parent->info) // if the value in the data field of the new node is less than that of the currentnode
		{
			parent->leftchild = newNode; // make the left child of the parent point to the new node
		}

		if (element > parent->info) // if the value in the data field of the new node is greater than that of the currentnode
		{
			parent->rightchild = newNode; // make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// this function searches the currentnode od thee specified node as well as the current node of it's parent
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

		void inorder(Node * ptr)
		{
			if (ROOT == nullptr)
			{
				cout << "Tree is empty" << endl;
				return;
			}
			if (ptr != nullptr)
			{
				inorder(ptr->leftchild);
				cout << ptr->info << " ";
				inorder(ptr->rightchild);
			}
		}

		void preorder(Node* ptr)
		{
			if (ROOT == nullptr)
			{
				cout << "Tree is empty" << endl;
				return;
			}
			if (ptr != nullptr)
			{
				cout << ptr->info << " ";
				inorder(ptr->leftchild);
				inorder(ptr->rightchild);
			}
		}
};