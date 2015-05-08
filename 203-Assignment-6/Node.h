#ifndef NODE_GO
#define NODE_GO
#include <string>
#include <iostream>
class Node
{
private:
	std::string mName;
	Node* mNext;
	Node* mPrev;
public:
	// constructors
	Node();
	Node(std::string myName);
	Node(std::string myName, Node&, Node&);
	// mutators
	bool setName(std::string const &);
	void Node::setNextNode(Node& );
	void Node::setPrevNode(Node& );
	// Accessors
	std::string getName();
	Node* getNextNode() const;
	Node* getPrevNode() const;
	~Node();
};

#endif