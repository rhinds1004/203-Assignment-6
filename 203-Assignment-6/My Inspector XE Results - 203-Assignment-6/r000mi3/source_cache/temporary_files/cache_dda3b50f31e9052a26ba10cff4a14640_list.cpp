#include "List.h"


List::List()
{
}

List::List(std::string myName)
{
	Node * newNode = new Node(myName);
	setHeadNode(newNode);
	setRearNode(newNode);
}
void List::setRearNode(Node* aNode)
{
	mRearNode = NULL;
}
void List::setHeadNode(Node* aNode)
{
	mHeadNode = aNode;
}
List::~List()
{

}
