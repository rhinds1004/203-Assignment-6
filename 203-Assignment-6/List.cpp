#include "List.h"


List::List()
{
}

List::List(std::string &myName)
{
	
	setHeadNode(Node(myName));
	setRearNode();
}
void List::setRearNode()
{
	mRearNode = NULL;
}
void List::setHeadNode(Node& aNode)
{
	mHeadNode = &aNode;
}
List::~List()
{
}
