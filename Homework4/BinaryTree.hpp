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
	//פעולת אתחול?
	//BSTree AddRightSon(BSNode newNode);
	//BSTree AddLeftSon(BSNode newNode);
	BSTree AddSon(BSNode newNode);
	BSTree FindNode(string Value);
	BSTree DeleteNode(string value);
};