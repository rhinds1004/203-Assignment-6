#include "Node.h"
#include "List.h"
using namespace std;
int main()
{
	/*Node n1;
	Node n2("w");
	Node n3("");
	n1.setName("Jackers");
	cout << n1.getName() << endl;
	cout << n2.getName();
	cout << n3.getName() << endl;

	n1.setNextNode(&n2);
	n2.setNextNode(&n3);
	n2.setPrevNode(&n1);
	cout << n1.getNextNode() << endl;
	cout << n2.getPrevNode() << endl;

	Node n4("Nikkers", n2, n1);
	cout << n4.getName() << endl;
	cout << n4.getNextNode() << endl;
	cout << n4.getPrevNode() << endl;*/
	string str1 = "wee";
	List alist(str1);
	/*List list2;
	Node start("into an empty list");
	list2.addFirst(&start);*/
	
	//list2.setHeadNode(&n1);
	
	alist.addFirst("Test");
	alist.addLast("Test2");
	if (alist.isEmpty() != true)
	{
		cout << "I have stuff" << endl;
	}
	cout << "my size is: " << alist.sizeMe() << endl;
	alist.removeFirst();
	alist.removeLast();
	alist.removeFirst();
	cout << "my size is: " << alist.sizeMe() << endl;
	cin.get();
	return 0;
}