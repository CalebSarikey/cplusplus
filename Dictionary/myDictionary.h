#ifndef MYDICTIONARY_H
#define MYDICTIONARY_H
#include <iostream>

using namespace std;

struct valueType   //the data type for the information
{
	double data1;
	double data2;
};

struct itemType    //the data type for each entry in the dictionary
{
	int key;       //the search key
	valueType value;  //the data
};


class myDictionary        //implementation of the dictionary using linear and quadratic probing
{
public:
	myDictionary(int n = 100, bool lin = true);
	//default constructor. Sets max Size of the dictionary to n.  Sets the collision resolution method
	// ALREADY IMPLEMENTED

	bool insert(itemType x, int &comp);
	//insert x into the dictionary, returns true if succesful.
	// Check if key is a duplicate.  If so, do nothing and return false.
	// comp returns the number of entries checked.
	//IF linearProbing is set to "true" use linear probing to resolve collisions
	//otherwise use quadratic probing.
	// ALREADY IMPLEMENTED

	bool search(int key, int &comp);
	// search for key in the dictionary, returns true if succesful.
	// comp returns the number of entries checked.

	bool remove(int key);
	// remove entry with key "key" from dictionary

	void print();
	//prints all the entries.  Already implemented
private:
	int maxSize;  //maximum size of the dictionary
	bool linearProbing;
	//the collision resolution method.  
	//If true "linear probing", otherwise "quadratic probing"
	itemType *A;   //the array containing all the data
	int *status;
	//an array containing the status information for each entry in A
	//-1 unoccupied, 1 occupied, 0 formerly occupied but now empty

	int h(int key);
	//hash function.  
	// ALREADY IMPLEMENTED
};


#endif // !MYDICTIONARY_H