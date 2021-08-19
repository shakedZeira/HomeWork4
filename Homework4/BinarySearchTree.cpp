#include "BinaryTreeNode.hpp"
#include "BinaryTree.hpp"
/////////////////////Binary Tree Node Class//////////////////
void BSNode::SetNodeData(string newData)
{
	data = newData;
}
BSNode* BSNode::NewNode(string newData)
{
	BSNode* NewNodeElement =  new BSNode();
	(*NewNodeElement).SetNodeData(newData);
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
/*
//first mission in the presention
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
BSNode* BSNode::AddSon(BSNode *existingNode ,string newdata)
{
	if (existingNode == NULL)
	{
		existingNode = NewNode(newdata);
		return existingNode;
	}
	else if (existingNode->data > newdata)
	{
		existingNode->leftSon = AddSon(existingNode->leftSon, newdata);
	}
	else
	{
		existingNode->rightSon = AddSon(existingNode->rightSon, newdata);
	}
}
BSNode* BSNode::FindNode(BSNode* existingNode ,string value)
{
	
	if (existingNode->data == value)
	{
		return existingNode;
	}
	else if (existingNode->data > value)
	{
		if (existingNode->leftSon != NULL)
		{
			FindNode(existingNode->leftSon, value);
		}
	}
	else if(existingNode->data < value)
	{
		if (existingNode->rightSon != NULL)
		{
			FindNode(existingNode->rightSon, value);
		}
	}
	else
	{
		cout << "the value isnt in the Tree" << endl;
	}
}
//changing
void BSNode::search(BSNode* root, string toFindData)
{
	BSNode* temp = new BSNode();
	temp = root;
	while (temp != NULL)
	{
		if (temp->data == toFindData)
		{
			cout << temp->data << endl;
			return;
		}
		else if(temp->data > toFindData)
		{
			temp = temp->leftSon;
		}
		else
		{
			temp = temp->rightSon;
		}
	}
}
BSNode* BSNode::DeleteNode(BSNode *existingNode, string value) //need to fix
{
	//finding the element to delete
	existingNode = FindNode(existingNode, value);
	if (existingNode->leftSon == NULL && existingNode->rightSon == NULL)
	{
		//need to do
		delete existingNode;
	}
	else if (!existingNode->leftSon)
	{
		BSNode temp = *existingNode->rightSon;
		//need to do
		delete existingNode;
		return &temp;
	}
	else if(!existingNode->rightSon)
	{
		BSNode temp = *existingNode->leftSon;
		//need to do
		delete existingNode;
		return &temp;
	}
	else
	{
		BSNode temp = *existingNode;
		while ((!temp.IsEmpty()) && temp.HasLeftSon())
		{
			temp = temp.GetLeftSon();
		}
		existingNode->SetNodeData(temp.GetNodeData());
		existingNode->rightSon = (DeleteNode(existingNode->rightSon, temp.GetNodeData()));
		return existingNode;
	}
}
//////////////////////////Binary Tree Class/////////////////
/*
* //first mission in the presention
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
BSNode* BSTree::AddSon(string newdata)
{
	return root->AddSon(root, newdata);
}
BSNode* BSTree::FindNode(string value)
{
	return root->FindNode(root, value);
}
BSNode* BSTree::DeleteNode(string value) //need to fix
{
	return root->DeleteNode(root, value);
}
void initlizeTree()
{
	BSTree Tree = BSTree();
	BSNode Node = BSNode();
	Node.SetNodeData("b");
	Node.AddSon(&Node, "c");
	Node.AddSon(&Node, "a");
	bool hasleftSon = Node.HasLeftSon();
	bool IsLeaf = Node.isLeaf();
	cout << hasleftSon << endl;
	cout << IsLeaf << endl;
	cout << "Data: " << Node.GetNodeData() << endl;
	cout << "Data left son: " << Node.GetLeftSon().GetNodeData() << endl;
	cout << "Data right son: " << Node.GetRightSon().GetNodeData() << endl;
	cout << "Find Node: " << Node.FindNode(&Node, "b")->GetNodeData() << endl;
	//need to fix deleted node
	//cout << "Deleted Node: " << Node.DeleteNode(&Node, "c");
	BSNode root = *Tree.AddSon("a");
	root.AddSon(&root, "b");
	cout << "data : " << root.GetNodeData() << endl;
	cout << "Right son data: " << root.GetRightSon().GetNodeData() << endl;
	cout<<"Node found: ";
	root.search(&root, "a");
}
int main()
{
	initlizeTree();
}
