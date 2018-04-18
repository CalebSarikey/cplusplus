#ifndef MYDICTIONARYSC_H
#define MYDICTIONARYSC_H
#include "myDictionary.h"
#include <iostream>

using namespace std;



struct itemTypeSC    //the data type for each entry in the dictionary
{
	int key;       //the search key
	valueType value;  //the data
	itemTypeSC *next; //pointer to next
};


class myDictionarySC        //implementation of the dictionary using separate chaining
{
public:
	myDictionarySC(int n = 100);
	//default constructor. Sets max Size of the dictionary to n. 
	// ALREADY IMPLEMENTED

	bool insert(itemTypeSC x);
	//insert x into the dictionary, returns true if succesful.
	// ALREADY IMPLEMENTED

	bool search(int key);
	// search for key in the dictionary, returns true if succesful.

	bool remove(int key);
	// search for key in the dictionary, returns true if succesful.

	void print();
	//prints all the entries.
	// ALREADY IMPLEMENTED

private:
	int maxSize;  //maximum size of the dictionary
	itemTypeSC **A;   //the array containing all the data
	int h(int key);
	//hash function.  
	// ALREADY IMPLEMENTED
};


#endif 