#pragma once
#include <iostream>
#include "BinaryTreeNode.hpp"
using namespace std;

class BSTree
{
private:
	BSNode* root;

public:
	BSTree()
	{
		root = NULL;
	}
	//����� �����?
	//BSTree AddRightSon(BSNode newNode);
	//BSTree AddLeftSon(BSNode newNode);
	BSNode GetRoot();
	BSNode AddSon(BSNode newNode);
	BSNode FindNode(string Value);
	BSNode DeleteNode(string value);
};