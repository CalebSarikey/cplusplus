#include <iostream>
#include <time.h>
#include <math.h>
#include <string>

#include "myBST.h"


using namespace std;




int main()
{
	myBST bT;
	char temp;
	const int maxElements = 15;
	string data = "";
	srand(time(NULL));
	for (int i = 0; i<maxElements; i++)
	{
		temp = rand() % 26 + 'A';
		data = data + temp;
	}
	//data="LEWAGCTFNYDO";
	for (int i = 0; i<data.length(); i++)
	{
		system("CLS");
		cout << data.substr(0, i + 1) << "\t\tNext :\t" << data[i + 1] << endl;
		bT.insertR(data[i]);
		bT.drawTree();
		system("pause");
	}
	
	cout << endl << "Tree height = " << bT.treeHeight() << endl;
	cout << endl << "#nodes = " << bT.getNoNodes() << endl;
	cout << "Preorder Traversal :";
	bT.preorderTraversal(); cout << endl;
	cout << "Inorder Traversal :";
	bT.inorderTraversal(); cout << endl;
	cout << "Postorder Traversal :";
	bT.postorderTraversal();
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter character to remove :" << endl;
		char ch;
		cin>>ch;
		bT.remove(ch);
		bT.drawTree();
	}

	system("pause");
	return 0;
}

