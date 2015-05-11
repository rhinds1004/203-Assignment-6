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
public:
	List();
	List(std::string );

	void setHeadNode(Node *);
	void setRearNode(Node *);
	~List();
};

#endif