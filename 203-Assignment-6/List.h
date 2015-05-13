#ifndef LIST_GO
#define List_GO
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
	bool addFirst(const std::string &);
	bool addLast(const std::string &myStr);
	bool removeFirst();
	bool removeLast();
	int sizeMe();
	bool isEmpty();
	// Destructors
	~List();
};

#endif