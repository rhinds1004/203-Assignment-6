#include "Node.h"
#include "List.h"
#include "Stack.h"
using namespace std;
int main()
{
	Node n1;
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
	cout << n4.getPrevNode() << endl;
	
	string str1 = "wee";
	List alist(str1);
	alist.addFirst("test");
	if (alist.isEmpty() != true)
	{
		cout << "I have stuff" << endl;
	}
	cout << "my size is: " << alist.sizeMe() << endl;
	alist.removeLast();
	cout << "this was the removed string:" << alist.removeFirst() << endl;
	alist.removeFirst();
	alist.removeFirst();
	cout << "this was the removed string:" << alist.removeLast() << endl;;
	alist.removeLast();
	cout << "my size is: " << alist.sizeMe() << endl;


	Stack myStack;
	myStack.push("Number 1");
	myStack.push("Number 2");
	myStack.push("Number 3");
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cin.get();
	return 0;
}