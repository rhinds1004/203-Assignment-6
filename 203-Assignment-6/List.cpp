//=========================================================================================
// Name : Robert Hinds
// Date : 5/12/15
// Class : TCES 203
// Description : This program creates and uses several abstract data types through
//	inheritance as well aggregation. The ADT’s used are nodes, lists, stacks,
//	and queues. The Node class is the base class which contains two pointers
//	to the next node and the previous node and a string for data. List is
//	comprised of a node by aggregation as well as node pointers to the front
//	and back of the list. Queue and Stack inherit list, meaning they ARE a
// kind of list, and each are comprised of a limited measure of the
// functionality of their base class List. Queue displays the classic
//	functionality of a queue, allowing for enqueuing (adding to the back) and
//	dequeuing (removing from the front). Stack also displays its classic
//	characteristics of push (adding to the top of the stack) and pop
//	(removing from the top of the stack). Throughout this program is
//	implemented a plethora of additional pre-requisite functionality such as
//	checking if a list is empty, determining the size of a list, overloaded
//	operators and etc.
//=========================================================================================
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
bool List::addFirst(const std::string &myStr)
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
std::string List::removeFirst()
{
	
	std::string retStr;
	if (mHeadNode == mRearNode)
	{
		if (mHeadNode != NULL && mRearNode != NULL)
		{
			retStr = mHeadNode->getName();
			delete mHeadNode;
			mHeadNode = NULL;
			mRearNode = NULL;
		}
	}
	if (mHeadNode != NULL)
	{
		Node * tempNode = mHeadNode->getNextNode();
		if (tempNode != NULL)
		{
			tempNode->setPrevNode(mHeadNode->getPrevNode()); //sets tempNode's rear to NULL;
			retStr = mHeadNode->getName();
			delete mHeadNode;
		}
		mHeadNode = tempNode;
		
	}
	return retStr;
}
//removal of last node in the list
std::string List::removeLast()
{
	std::string retStr;
	if (mHeadNode == mRearNode)
	{
		if (mHeadNode != NULL && mRearNode != NULL)
		{
			retStr = mHeadNode->getName();
			delete mHeadNode;
			mHeadNode = NULL;
			mRearNode = NULL;
		}

	}
	if (mHeadNode != NULL)
	{
		Node * tempNode = mRearNode->getPrevNode();
		if (tempNode != NULL)
		{
			tempNode->setNextNode(mRearNode->getNextNode()); //sets tempNode's next to NULL;
			retStr = mHeadNode->getName();
			delete mRearNode;		
		}
		mRearNode = tempNode;
	}
	return retStr;
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
void List::printMe(std::ostream& tempStrm, List &aList, const std::string& type) const
{
	//case 1: string is empty

	if (aList.isEmpty())
	{
		tempStrm << "The "<< type <<" is empty.";
		//return tempStrm;
	}
	//case 2: there is only one node in the list
	else if (aList.mHeadNode == aList.mRearNode)
	{
		tempStrm << "Printing " << type << " by name:" << "NULL<--" << aList.mHeadNode->getName() << "-->NULL";
		//return tempStrm;
	}
	//case 3: standard case, there is more than one node in the list
	else
	{
		Node* temp = aList.mHeadNode;
		tempStrm << "Printing "<< type << " by name:" << "NULL";
		while (temp != NULL)
		{
			tempStrm << "<--" << temp->getName() << "-->";
			temp = temp->getNextNode();
		}
		tempStrm << "NULL";
	}
	//return tempStrm;
}
//overloaded operators
//overloads ostream cout to print a List object by displaying the nodes in the list in order by name
std::ostream &operator << (std::ostream &tempStrm, List &aList)
{
	aList.printMe(tempStrm, aList, "list");
	return tempStrm;
}

//check if dynamically allocated Node needs to be deleted.
List::~List()
{
	if (mHeadNode != NULL)
	{
	
		Node* tempNode = mHeadNode->getNextNode();
		do
		{
			delete mHeadNode;
			mHeadNode = NULL;
			mHeadNode = tempNode;
			if (mHeadNode != NULL)
			{
				tempNode = mHeadNode->getNextNode();
			}
			else
				tempNode = NULL;
		} while (tempNode != NULL);
	}
	mRearNode = NULL;
}
