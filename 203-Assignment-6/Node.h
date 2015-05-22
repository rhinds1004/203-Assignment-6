#ifndef NODE_GO
#define NODE_GO
#include <string>
#include <iostream>
#include <cstdlib>
class Node
{
	friend class List;
private:
	std::string mName;
	Node* mNext;
	Node* mPrev;

	// constructors
	Node();
	Node(std::string myName);
	Node(std::string myName, Node&, Node&);
	// mutators
	bool setName(std::string const &);
	void setNextNode(Node* );
	void setPrevNode(Node* );
	// Accessors
	std::string getName();
	Node* getNextNode() const;
	Node* getPrevNode() const;
	void testNode();
	// Destructors
	~Node();
public:
	
};

#endif