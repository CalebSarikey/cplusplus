#include "myLinkedList.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "Testing Linked List Reversal ..." << endl;
	myLinkedList L1;
	int n = 20;
	for (int i = 0; i<n; i++)
		L1.insert(rand() % 201 - 100);
	cout << "\nOriginal list :\n";
	L1.printList();
	L1.reverseList();
	cout << "\nList after reversal :\n";
	L1.printList();
    
	cout << endl;
	system("pause");
    return 0;
}
