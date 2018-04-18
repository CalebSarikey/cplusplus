
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

//create a class for a linked list of doubles

//create a structure for each node of the LL
struct nodeType {
	double data;     //where information is stored
	nodeType* next;   //link (address) to the next node
};


class myLinkedList
{
public:
	myLinkedList(); //default constructor to initialize the list
	void insert(double x); //insert element x into the list (insert at the beginning)
	void printList();  //print the contents of the list
	void printListR();  //prints the list using a recursive function
	void printRevList();  //print the list in reverse order
	void remove(); //delete the first element of the list

	void insertS(double x);
	//insert element x into the list, just before the first element greater than x

	double getMax();  //a recursive function that returns the largest element in the list;
	void emptyList(); //empties the list
	~myLinkedList();  //destructor

	//NEW FUNCTION YOU NEED TO IMPLEMENT
	void reverseList();  //a function that reverses the list 

private:
	nodeType* head;  //pointer to the first element of the list
	void printHelper(nodeType* L);
	//a function to help with printing recursively
	//given L, it will print the contents of L recursively

	void printRevHelper(nodeType* L);
	double getMaxHelper(nodeType* L);
};






#endif
