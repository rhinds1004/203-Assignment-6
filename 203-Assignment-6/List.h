#ifndef LIST_GO
#define List_GO
#include "Node.h"
class List
{
private:
	Node* mHeadNode;
	Node* mRearNode;
	Node* mNewNode;
	void setNewNode(Node *);
protected:
	
public:
	// constructors
	List();
	List(std::string );
	// mutators
	void setHeadNode(Node *);
	void setRearNode(Node *);
	bool listStarterNode(Node* );
	bool addFirst(Node*);
	bool addLast(Node* );
	bool removeFirst();
	bool removeLast();
	int sizeMe();
	bool isEmpty();
	// Destructors
	~List();
};

#endif