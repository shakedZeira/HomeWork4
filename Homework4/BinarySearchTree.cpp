#include "BinaryTreeNode.hpp"
#include "BinaryTree.hpp"
/////////////////////Binary Tree Node Class//////////////////
void BSNode::SetNodeData(string newData)
{
	data = newData;
}
BSNode BSNode::NewNode(string newData)
{
	BSNode NewNodeElement = BSNode();
	NewNodeElement.SetNodeData(newData);
	return NewNodeElement;
}
bool BSNode::isLeaf()
{
	if ((leftSon == NULL) && (rightSon == NULL))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BSNode::HasRightSon()
{
	if (rightSon == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool BSNode::HasLeftSon()
{
	if (leftSon == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool BSNode::IsEmpty()
{
	if (data == "")
	{
		return true;
	}
	else
	{
		return false;;
	}
}
string BSNode::GetNodeData()
{
	return data;
}
BSNode BSNode::GetRightSon()
{
	return *rightSon;
}
BSNode BSNode::GetLeftSon()
{
	return *leftSon;
}
void BSNode::SetRightSonData(string newData)
{
	rightSon->SetNodeData(newData);
}
void BSNode::SetLeftSonData(string newData)
{
	leftSon->SetNodeData(newData);
}
//need to check!!!
/*
BSNode BSNode::AddRightSon(BSNode existingElement,BSNode newNodeElement)
{
	if (existingElement.GetRightSon().GetNodeData() != newNodeElement.GetNodeData())
	{
		//existingElement.SetRightSonData(newNodeElement.GetNodeData());
		*existingElement.rightSon = newNodeElement;
		return *existingElement.rightSon;
	}
	else
	{
		AddRightSon(existingElement.GetRightSon(), newNodeElement);
	}
}
BSNode BSNode::AddLeftSon(BSNode existingElement,BSNode newNodeElement)
{
	if (existingElement.GetLeftSon().GetNodeData() != newNodeElement.GetNodeData())
	{
		//existingElement.SetLeftSonData(newNodeElement.GetNodeData());
		*existingElement.leftSon = newNodeElement;
		return *existingElement.leftSon;
	}
	else
	{
		AddLeftSon(existingElement.GetLeftSon(), newNodeElement);
	}
}
*/
//need to check!!
BSNode BSNode::AddSon(BSNode existingNode , BSNode newNode)
{
	if (existingNode.IsEmpty())
	{
		return NewNode(newNode.GetNodeData());
	}
	else if (existingNode.GetNodeData() > newNode.GetNodeData())
	{
		existingNode.GetLeftSon() = AddSon(existingNode.GetLeftSon(), newNode);
	}
	else
	{
		existingNode.GetRightSon() = AddSon(existingNode.GetRightSon(), newNode);
	}
}
//pointer?
BSNode BSNode::FindNode(BSNode existingNode ,string value)
{
	if (existingNode.GetNodeData() == value)
	{
		return existingNode;
	}
	else if (existingNode.GetNodeData() > value)
	{
		FindNode(existingNode.GetLeftSon(), value);
	}
	else if(existingNode.GetNodeData() < value)
	{
		FindNode(existingNode.GetRightSon(), value);
	}
	else
	{
		cout << "the value isnt in the Tree" << endl;
	}
}
BSNode BSNode::DeleteNode(BSNode existingNode, string value)
{
	//finding the elemet to delete
	existingNode = FindNode(existingNode, value);
	if (existingNode.isLeaf())
	{
		//need to do
		//delete *existingNode;
	}
	else if (!existingNode.HasLeftSon())
	{
		BSNode temp = existingNode.GetRightSon();
		//need to do
		//delete existingNode;
		return temp;
	}
	else if(!existingNode.HasRightSon())
	{
		BSNode temp = existingNode.GetLeftSon();
		//need to do
		//delete existingNode;
		return temp;
	}
	else
	{
		BSNode temp = existingNode;
		while ((!temp.IsEmpty()) && temp.HasLeftSon())
		{
			temp = temp.GetLeftSon();
		}
		existingNode.SetNodeData(temp.GetNodeData());
		existingNode.GetRightSon() = DeleteNode(existingNode.GetRightSon(), temp.GetNodeData());
		return existingNode;
	}
}
//////////////////////////Binary Tree Class/////////////////
/*
BSTree BSTree::AddRightSon(BSNode newNode)
{
	root->AddRightSon(*root, newNode);
}
BSTree BSTree::AddLeftSon(BSNode newNode)
{
	root->AddLeftSon(*root, newNode);
}
*/
BSNode BSTree::GetRoot()
{
	return *root;
}
BSNode BSTree::AddSon(BSNode newNode)
{
	return root->AddSon(*root, newNode);
}
BSNode BSTree::FindNode(string value)
{
	return root->FindNode(*root, value);
}
BSNode BSTree::DeleteNode(string value)
{
	return root->DeleteNode(*root, value);
}


int main()
{
	BSTree Tree = BSTree();
	BSNode Node = BSNode();
	Node.SetNodeData("aa");
	Tree.AddSon(Node);
	cout<<"Root :" << Tree.GetRoot().GetNodeData()<<endl;
}