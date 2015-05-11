#include "Node.h"

//********	 Constructors	********
Node::Node()
{
	mName = "";
	mNext = NULL;
	mPrev = NULL;
}
//OverLoaded constructor. Initilizes object name value with given string.
Node::Node(std::string myName)
{
	setName(myName);
	mNext = NULL;
	mPrev = NULL;
}
//OverLoaded constructor. Initilizes object name value with given string, next node pointer to nextNode's 
// address and previous node pointer to prevNode's address.
Node::Node(std::string myName, Node& nextNode , Node& prevNode)
{
	if (setName(myName) == false)
	{
		setName("default");
	}
	mNext = &nextNode;
	mPrev = &prevNode;
}
//********		Mutators	********
//Returns a true value if given parameter is not empty and has more than 2 characters.
//Returns false otherwise.
bool Node::setName(std::string const &nameStr)
{
	bool status;
	if (!nameStr.empty() && nameStr.length() > 2)
	{
		//std::string name(nameStr);
		mName = nameStr;
		status = true;
	}
	
	else if (nameStr.empty())
	{ 
		std::cout << "*Error* Name can not be left empty" << std::endl;
		 status = false;
	}
	else
	{
		std::cout << "*Error* Name must be greater than 2 characters" << std::endl;
		status = false;
	}
	
	return status;
}

//Sets a Node Pointer to the next Node in the list.
void Node::setNextNode(Node& inputPtr) 
{
	mNext = &inputPtr;
}
//Sets a Node Pointer to the previous Node in the list.
void Node::setPrevNode(Node&  inputPtr) 
{
	mPrev = &inputPtr;
}

// ********		Accessors	********
//Returns the name value stored in the Node.
std::string Node::getName()
{
	return mName;
}

//Returns a Node Pointer to the next Node in the list.
Node* Node::getNextNode() const
{
	return mNext;
}

//Returns a Node Pointer to the previous Node in the list.
Node* Node::getPrevNode() const
{
	return mPrev;
}

//Destorys!!
Node::~Node()
{
}
