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

//Records the address of the Node dynamically allocated in the constructor.
//to allow deleting.
void List::setNewNode(Node* aNode)
{
	mNewNode = aNode;
}
//Function to check if dynamically allocated Node needs to be deleted.?
List::~List()
{
	delete mNewNode;
}
