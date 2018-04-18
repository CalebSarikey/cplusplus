#include "myDictionary.h"
#include "myDictionarySC.h"
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////
/* linear and quadratic probing function implementations */
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


myDictionary::myDictionary(int n, bool lin)
{
	maxSize = n;          //set the max size
	linearProbing = lin;  //set the method
	A = new itemType[n]; //allocate memory for A
	status = new int[n];  //allocate memory for status
	for (int i = 0; i<n; i++)
		status[i] = -1;   //set the status of each index to "unoccupied"
}

int myDictionary::h(int key)
{
	return key%maxSize;    //hash function using modulus operator
}


void myDictionary::print()
{
	cout << "Index\tKey\t Value\n";
	for (int i = 0; i < maxSize; i++)
	{
		cout << i;
		if (status[i] == 1)  //if it is currently occupied print the information
			cout << "\t" << A[i].key << "\t{" << A[i].value.data1 << "," << A[i].value.data2 << "}\n";
		else
			cout << endl;

	}
}


bool myDictionary::insert(itemType x, int &comp)
{
	int ind = h(x.key);   //get index from hash function
	if (linearProbing)
	{
		int i = 0;
		while (status[(ind + i) % maxSize] == 1)
		{
			if (A[(ind + i) % maxSize].key == x.key)
				return false; //duplicate key
			i++;
		}
		A[(ind + i) % maxSize] = x;
		status[(ind + i) % maxSize] = 1;
		comp = i + 1;
		return true;
	}
	else
	{
		int i = 0;
		while (status[(ind + i*i) % maxSize] == 1)
		{
			if (A[(ind + i*i) % maxSize].key == x.key)
				return false; //duplicate key
			i++;
		}
		A[(ind + i*i) % maxSize] = x;
		status[(ind + i*i) % maxSize] = 1;
		comp = i + 1;
		return true;
	}
}
/////////////////////////////////////////////////////////////
/*  separate chaining dictionary fucntion implementations*/
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

myDictionarySC::myDictionarySC(int n)
{
	maxSize = n;          //set the max size
	A = new itemTypeSC*[n]; //allocate memory for A
	for (int i = 0; i<n; i++)
		A[i] = nullptr;   //set the status of each entry to nullptr
}

int myDictionarySC::h(int key)
{
	return key%maxSize;    //hash function using modulus operator
}


void myDictionarySC::print()
{
	cout << "Index\t[Key\t {Value}];\n";
	for (int i = 0; i < maxSize; i++)
	{
		cout << i;
		if (A[i] != nullptr)
		{
			itemTypeSC *w = A[i];
			cout << "\t";
			while (w != nullptr)
			{
				cout << "[" << w->key << "\t{" << w->value.data1 << "," << w->value.data2 << "}]; ";
				w = w->next;
			}
			cout << endl;
		}
		else
			cout << endl;

	}
}


bool myDictionarySC::insert(itemTypeSC x)
{
	int ind = h(x.key);   //get index from hash function
	itemTypeSC *newItem = new itemTypeSC;
	*newItem = x;
	newItem->next = A[ind];
	A[ind] = newItem;
	return true;
}

////////////////////////////////////////////////////////////
/*         remove/search function implementations         */
////////////////////////////////////////////////////////////

bool myDictionary::remove(int key) {
	int ind = h(key);   //get index from hash function
	if (linearProbing)
	{
		int i = 0;
		while (status[(ind + i) % maxSize] == 1)
		{
			//if the key is found, set it's status to 0 and return true
			if (A[(ind + i) % maxSize].key == key) {
				status[(ind + i) % maxSize] = 0;	//set to 0 for empty, but formerly occupied
				return true;
			}
			i++;
		}
		return false;  //return false if nothing removed
	}
	else
	{
		int i = 0;
		while (status[(ind + i*i) % maxSize] == 1)
		{
			//if key is found, set status to 0 and return true
			if (A[(ind + i*i) % maxSize].key == key) {
				status[(ind + i*i) % maxSize] = 0;	//set to 0 for empty, but formerly occupied
				return true;
			}
			i++;
		}
		return false;  //return false if nothing removed
	}
}

bool myDictionary::search(int key, int &comp) {
	int ind = h(key);   //get index from hash function
	if (linearProbing)
	{
		int i = 0;
		while (status[(ind + i) % maxSize] == 1)
		{
			//if the key is found, return true
			if (A[(ind + i) % maxSize].key == key)
				return true;
			comp = i + 1;
			i++;
		}
		return false;  //return false if nothing is found
	}
	else
	{
		int i = 0;
		while (status[(ind + i*i) % maxSize] == 1)
		{
			//if the key is found, return true
			if (A[(ind + i*i) % maxSize].key == key)
				return true;
			comp = i + 1;
			i++;
		}
		return false; //return false if nothing is found
	}
}

bool myDictionarySC::search(int key) {
	int ind = h(key);   //get index from hash function
	if (A[ind] != nullptr)
	{
		itemTypeSC *w = A[ind];
		while (w != nullptr)
		{
			//if key is at current position, return true
			if (w->key == key)
				return true;
			//otherwise, step to the next element of the list
			else
				w = w->next;
		}
	}
	return false;
}

bool myDictionarySC::remove(int key) {
	int ind = h(key);   //get index from hash function
	//check entries at each position with something there
		if (A[ind] != nullptr)
		{
			//to hold previous, current, and next in the linked list
			itemTypeSC *prev = nullptr;
			itemTypeSC *current = A[ind];
			itemTypeSC *next;
			while (current != nullptr) {
				next = current->next;
				if (current->key == key) {
					//case for if first element is to be removed
					//update pointers, remove entry, return true
					if (prev == nullptr) {
						prev = current;
						current = current->next;
						prev->next = nullptr;
						delete prev;
						A[ind] = current;
						return true;
					}
					//case for any element other than the first
					//update pointers, remove entry, return true
					prev->next = current->next;
					current->next = nullptr;
					delete current;
					current = next;
					return true;
				}
				else {
					//if not found, update to next position in list
					prev = current;
					current = next;
				}
			}
		}
	return false;	//return false if nothing removed
}
