#include "myDictionary.h"
#include "myDictionarySC.h"
#include <iostream>

using namespace std;


int main()
{
	int size = 100;
	int M = 80;
	myDictionary dl(size),  //dictionary with linear probing
		dq(size, false); //dictionary with QUADRATIC probing
	itemType entry;
	int *allkeys = new int[M];
	int lcomp, qcomp, ltot = 0, qtot = 0;
	
	cout << "TESTING INSERT ...\n\n";
	for (int i = 0; i < M; i++)
	{
		int k = rand() % 1000000;  //random generate the data
		entry.key = k;
		allkeys[i] = k;
		entry.value.data1 = rand() % 200 - 500;
		entry.value.data2 = rand() % 10 - 10.5;
		if (dl.insert(entry, lcomp))
			ltot += lcomp;
		if (dq.insert(entry, qcomp))
			qtot += qcomp;
	}
	cout << "Using LINEAR probing there were " << ltot << " comparisons performed for all insertions\n";
	cout << "Using QUADRATIC probing there were " << qtot << " comparisons performed for all insertions\n";
	cout << "\nLINEAR:\n";
	dl.print();

	cout << "\nQUADRATIC:\n";
	dq.print();

	system("pause");

	
	cout << "TESTING REMOVE ...\n\n";
	for (int i = 0; i<3; i++)
	{
		int kk;
		cout << "Enter a key to remove: ";
		cin >> kk;
		dl.remove(kk);
		dq.remove(kk);
	}

	cout << "\nLINEAR after removal:\n";
	dl.print();
	cout << "\nQUADRATIC after removal:\n";
	dq.print();



	system("pause");

	
	cout << "TESTING SEARCH ...\n\n";
	int fl = 0, fq = 0;

	for (int i = 0; i < 3; i++)
	{
		int kk;
		cout << "Enter a key to search for: ";
		cin >> kk;
		cout << "LINEAR PROBING : ";
		if (dl.search(kk, lcomp))
			cout << "FOUND! Used " << lcomp << " comparisons." << endl;
		else
			cout << "NOT FOUND!  Used " << lcomp << " comparisons." << endl;

		cout << "QUADRATIC PROBING : ";
		if (dq.search(kk, qcomp))
			cout << "FOUND! Used " << qcomp << " comparisons." << endl;
		else
			cout << "NOT FOUND!  Used " << qcomp << " comparisons." << endl;

	}


	system("pause");
	system("cls");
	
	


	cout << "TESTING INSERT FOR SEPARATE CHAINING\n";
	myDictionarySC dsc(size);  //dictionary with separate chaining
	itemTypeSC entrySC;
	entrySC.next = nullptr;
	for (int i = 0; i < M; i++)
	{
		int k = rand() % 1000000;  //random generate the data
		entrySC.key = k;
		allkeys[i] = k;
		entrySC.value.data1 = rand() % 200 - 500;
		entrySC.value.data2 = rand() % 10 - 10.5;
		dsc.insert(entrySC);
	}
	dsc.print();

	system("pause");

	
	cout << "TESTING REMOVE FOR SEPARATE CHAINING\n";
	for (int i = 0; i < 3; i++)
	{
	int kk;
	cout<<"Enter a key to remove: ";
	cin>>kk;
	dsc.remove(kk);
	}
	cout<<"Dictionary after removal:\n";
	dsc.print();


	system("pause");
	

	cout << "TESTING SEARCH FOR SEPARATE CHAINING\n";
	for (int i = 0; i < 3; i++)
	{
	int kk;
	cout << "Enter a key to search for: ";
	cin >> kk;
	if (dsc.search(kk))
		cout<<"FOUND!"<<endl;
	else
		cout << "NOT FOUND!" << endl;
	}

	system("pause");

	return 0;
}