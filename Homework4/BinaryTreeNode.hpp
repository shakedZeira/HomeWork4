#pragma once
#include <iostream>
#include <string>
using namespace std;

class BSNode
{
private:
	string data;
	BSNode* leftSon;
	BSNode* rightSon;
	int count;
public:
	BSNode()
	{
		data = " ";
		leftSon = NULL;
		rightSon = NULL;
		count = 0;
	}
	void SetNodeData(string newData);
	BSNode* NewNode(string newData);
	bool isLeaf();
	bool HasRightSon();
	bool HasLeftSon();
	bool IsEmpty();
	string GetNodeData();
	BSNode GetRightSon();
	BSNode GetLeftSon();
	void SetRightSonData(string newdata);
	void SetLeftSonData(string newdata);
	//BSNode AddRightSon(BSNode existingNode,BSNode newNode);
	//BSNode AddLeftSon(BSNode existingNode,BSNode newNode);
	BSNode* AddSon(BSNode *existingNode , string newdata);
	BSNode* DeleteNode(BSNode *existingNode, string value);
	void search(BSNode* existingNode, string value);
};



















/*

struct Node
{
	string data;
	Node* left;
	Node* Right;
	int count;
};
class BinarySearchTree
{

private:
	Node* root;

public:
	BinarySearchTree()
	{
		root->data = "";
		root->left = NULL;
		root->Right = NULL;
		root->count = 1;

	}

	Node NewNode(string NewData)
	{
		Node* New_Node = new Node();
		New_Node->data = NewData;
		New_Node->left = NULL;
		New_Node->Right = NULL;

		return *New_Node;

	}

	bool IsLeaf()
	{
		if (HasRightSon() == false && HasLeftSon() == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool HasRightSon()
	{
		if (root->Right == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool HasLeftSon()
	{
		if (root->left == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void AddLeftSon(Node* leftson)
	{
		if (leftson->data[0] < root->data[0])
		{
			root->left = leftson;
		}

	}
	void AddRightSon(Node* Rightson)
	{
		if (Rightson->data[0] > root->data[0])
		{
			root->Right = Rightson;
		}

	}
	Node* MinvalueNode(Node* node)
	{
		Node* current = node;
		while (current && current->left != NULL)
		{
			current = current->left;
		}
	}
	Node* FindElement(Node* root, string value)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else if (root->data == value)
		{
			return root;
		}
		else if (root->data[0] > value[0])
		{
			root->left = FindElement(root->left, value);
		}
		else if (root->data[0] < value[0])
		{
			root->Right = FindElement(root->Right, value);
		}
	}
	Node* DeleteNode(Node* root, string value)
	{
		if (root == NULL)
		{
			cout << "The Tree is empty!" << endl;
		}
		else if (root->data[0] > value[0])
		{
			root->left = DeleteNode(root->left, value);
		}
		else if (root->data[0] < value[0])
		{
			root->Right = DeleteNode(root->left, value);
		}
		else
		{
			if (root->left == NULL && root->Right == NULL)
			{
				return NULL;
			}
			else if (root->left != NULL)
			{
				Node* temp = root->Right;
				delete(root);
				return temp;
			}
			else if (root->Right != NULL)
			{
				Node* temp = root->left;
				delete(root);
				return temp;
			}
			Node* temp = MinvalueNode(root->Right);
			root->data = temp->data;

			root->Right = DeleteNode(root->Right, temp->data);
		}
	}
};
*/