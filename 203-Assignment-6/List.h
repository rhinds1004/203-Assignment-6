#ifndef LIST_GO
#define LIST_GO
#include "Node.h"
class List
{
private:
	Node* mHeadNode;
	Node* mRearNode;
protected:
	
public:
	// constructors
	List();
	List(std::string );
	// mutators
	void setHeadNode(Node *);
	void setRearNode(Node *);
	bool listStarterNode(Node* );
	bool addFirst(const std::string &myStr);
	bool addLast(const std::string &myStr);
	std::string removeFirst();
	std::string removeLast();
	int sizeMe();
	bool isEmpty();
	// Destructors
	~List();
};

#endif