#include "List.h"

//********	 Constructors	********
List::List()
{
	mHeadNode = NULL;
	mRearNode = NULL;
	mNewNode = NULL;
}

List::List(std::string myName)
{
	Node * newNode = new Node(myName);
	setHeadNode(newNode);
	setRearNode(newNode);
	setNewNode(newNode);
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
bool List::addFirst(Node* aNode)
{
	bool status = false;
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
bool List::addLast(Node* aNode)
{
	bool status = false;
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
			if (mHeadNode == mNewNode)						  //ensures dynamically allocated Node gets deallocated.
			{
				delete mHeadNode;
				mHeadNode = NULL;
				mRearNode = NULL;
				mNewNode = NULL;
			}
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
			if (mHeadNode == mNewNode)						//ensures dynamically allocated Node gets deallocated.
			{
				delete mHeadNode;
				mHeadNode = NULL;
				mRearNode = NULL;
				mNewNode = NULL;
			}
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
//Records the address of the Node dynamically allocated in the constructor.
//to allow deleting.
void List::setNewNode(Node* aNode)
{
	mNewNode = aNode;
}
//Function to check if dynamically allocated Node needs to be deleted.?
List::~List()
{
	if (mNewNode != NULL)
	{
		delete mNewNode;
	}
}
