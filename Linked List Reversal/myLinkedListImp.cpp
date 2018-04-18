#include "myLinkedList.h"  //for my linked list class definition
#include <iostream>   //cin, cout

using namespace std;

void myLinkedList::reverseList() {
	nodeType * prev = nullptr;
	nodeType * current = head;
	nodeType * next;

	//walk through list and change pointers
	while (current != nullptr) {
		//update pointers
		next = current->next;
		current->next = prev;
		//step through
		prev = current;
		current = next;
	}
	//put last element at front of list
	head = prev;
}



myLinkedList::myLinkedList() //default constructor to initialize the list
{
	head = nullptr;
}

void myLinkedList::insert(double x) //insert element x into the list (insert at the beginning)
{
	nodeType* newnode;
	newnode = new nodeType;
	newnode->data = x;
	newnode->next = head;
	head = newnode;
}

void myLinkedList::insertS(double x)
//insert element x into the list, just before the first element greater than x
{
	nodeType *newnode, *walker;
	newnode = new nodeType;
	newnode->data = x;
	newnode->next = nullptr;
	if (head == nullptr)   //special case #1 -> list is empty
		head = newnode;
	else if (head->data > x)  //special case #2 -> insert at the beginning
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		walker = head;
		while (walker->next != nullptr)
		{
			if (walker->next->data > x)
				//walker is the pointer to the node after which we want to insert
			{
				newnode->next = walker->next;
				walker->next = newnode;
				return;
			}
			walker = walker->next;
		}
		//insert at the end (i.e., insert after walker)
		newnode->next = walker->next;
		walker->next = newnode;

	}

}


void myLinkedList::printList()  //print the contents of the list
{
	nodeType* walker = head;
	cout << "{";
	while (walker != nullptr)
	{
		cout << walker->data << ", ";
		walker = walker->next;
	}
	cout << "}";
}

void myLinkedList::printListR()  //prints the list using a recursive function
{
	cout << "{";
	printHelper(head);  //simply call the Helper function
	cout << "}";
}

void myLinkedList::printHelper(nodeType* L)
{
	if (L != nullptr)
	{
		cout << L->data << ", ";
		printHelper(L->next);
	}
}


void myLinkedList::printRevList()  //prints the reverse list using a recursive function
{
	cout << "{";
	printRevHelper(head);  //simply call the Helper function
	cout << "}";
}

void myLinkedList::printRevHelper(nodeType* L)
{
	if (L != nullptr)
	{
		printRevHelper(L->next);
		cout << L->data << ", ";
	}
}

void myLinkedList::remove() //delete the first element of the list
{
	if (head != nullptr)
	{
		nodeType* temp = head;
		head = head->next;
		delete temp;
	}
}

double myLinkedList::getMax()  //a recursive function that returns the largest element in the list;
{
	return getMaxHelper(head);
}

double myLinkedList::getMaxHelper(nodeType* L)
//return the largest element of a list  L
{
	if (L == nullptr)
		return -9999999;
	double tm1 = L->data;
	double tm2 = getMaxHelper(L->next);
	if (tm1 > tm2)
		return tm1;
	else
		return tm2;
}

void myLinkedList::emptyList()
{
	nodeType *walker = head, *x;
	head = nullptr;
	while (walker != nullptr)
	{
		x = walker;
		walker = walker->next;
		delete x;
	}
}

myLinkedList::~myLinkedList()
{
	emptyList();
}
