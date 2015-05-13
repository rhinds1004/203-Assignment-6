#include "List.h"

//********	 Constructors	********
List::List()
{
	mHeadNode = NULL;
	mRearNode = NULL;
}

List::List(std::string myName)
{
	Node * newNode = new Node(myName);
	setHeadNode(newNode);
	setRearNode(newNode);
}

//********		Mutators	********
//sets pointer to the last node in the list
void List::setRearNode(Node* aNode)
{
	mRearNode = aNode;
}
//sets pointer to the first node in the list
void List::setHeadNode(Node* aNode)
{
	mHeadNode = aNode;
}
//adds a node in an empty list
bool List::listStarterNode(Node* aNode)
{
	bool status = false;
	
		setHeadNode(aNode);
		setRearNode(aNode);
		status = true;
	
	return status;
}
//adds node to the beginning of list
bool List::addFirst( const std::string &myStr)
{
	bool status = false;
	Node * aNode = new Node(myStr);
	if (mHeadNode == NULL)
	{
		return listStarterNode(aNode);

	}
	else
	{
		aNode->setNextNode(mHeadNode);
		mHeadNode->setPrevNode(aNode);
		mHeadNode = aNode;
		status = true;
	}
	return status;
}
//adds node to the end of list
bool List::addLast(const std::string &myStr)
{
	bool status = false;
	Node * aNode = new Node(myStr);
	if (mHeadNode == NULL)
	{
		return listStarterNode(aNode);
	}
	else
	{
		aNode->setPrevNode(mRearNode);
		mRearNode->setNextNode(aNode);
		mRearNode = aNode;
		status = true;
	}
	return status;
}
//removal of first node in the list
bool List::removeFirst()
{
	bool status = false;
	if (mHeadNode != NULL)
	{
		
		Node * tempNode = mHeadNode->getNextNode();
		if (tempNode != NULL)
		{
			tempNode->setPrevNode(mHeadNode->getPrevNode()); //sets tempNode's rear to NULL;
			delete mHeadNode;  //ensures dynamically allocated Node gets deallocated.
			mHeadNode = NULL;
			mRearNode = NULL;
						
		}
		mHeadNode = tempNode;
		status = true;
	}
	return status;
}
//removal of last node in the list
bool List::removeLast()
{
	bool status = false;
	if (mHeadNode != NULL)
	{
		Node * tempNode = mRearNode->getPrevNode();
		if (tempNode != NULL)
		{
			tempNode->setNextNode(mRearNode->getNextNode()); //sets tempNode's next to NULL;
				delete mHeadNode;
				mHeadNode = NULL;
				mRearNode = NULL;
				
		}
		mRearNode = tempNode;
		status = true;
	}
	return status;
}
//returns the amount of nodes within a list.
int List::sizeMe()
{
	int size = 0;
	Node* tempNode = mHeadNode;
	while (tempNode != NULL)
	{
		size++;
		tempNode = tempNode->getNextNode();
	}
	return size;
}
//checks to see if the list is empty.
bool List::isEmpty()
{
	bool status = true;
	if (mHeadNode == NULL)
		return status ;
	return status = false;
}

//Function to check if dynamically allocated Node needs to be deleted.?
List::~List()
{
	Node* tempNode = mHeadNode->getNextNode();
	while (mHeadNode != NULL)
	{
		delete mHeadNode;
		mHeadNode = NULL;
		mHeadNode = tempNode;
		tempNode = mHeadNode->getNextNode();
		
	}
}
