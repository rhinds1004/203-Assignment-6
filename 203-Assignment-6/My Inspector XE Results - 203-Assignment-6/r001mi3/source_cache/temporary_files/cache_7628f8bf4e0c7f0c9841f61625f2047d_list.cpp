#include "List.h"


List::List()
{
}

List::List(std::string myName)
{
	Node * newNode = new Node(myName);
	setHeadNode(newNode);
	setRearNode(newNode);
	setNewNode(newNode);
}
void List::setRearNode(Node* aNode)
{
	mRearNode = aNode;
}
void List::setHeadNode(Node* aNode)
{
	mHeadNode = aNode;
}
void List::setNewNode(Node* aNode)
{
	mNewNode = aNode;
}
List::~List()
{
	mNewNode->~Node();
}
