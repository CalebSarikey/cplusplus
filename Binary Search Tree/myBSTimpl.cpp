#include "myBST.h"
#include <iostream>

using namespace std;

myBST::myBST()
{
	root = nullptr;
}



void myBST::insert(char indata)
{
	if (root == nullptr) //case 0 - the tree is empty
	{
		root = new binNode;
		root->item = indata;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		binNode *walk = root, *parent = root;
		while (walk != nullptr)  //getting to a leaf position to insert
		{
			parent = walk;
			if (indata<walk->item)
				walk = walk->left;
			else if (indata>walk->item)
				walk = walk->right;
			else
				return;
		}
		if (indata<parent->item)
		{
			parent->left = new binNode;
			parent->left->item = indata;
			parent->left->left = nullptr;
			parent->left->right = nullptr;
		}
		else
		{
			parent->right = new binNode;
			parent->right->item = indata;
			parent->right->left = nullptr;
			parent->right->right = nullptr;
		}
	}
}





int myBST::treeHeight()
{
	return subtreeHeight(root);
}

int myBST::subtreeHeight(binNode* tr)
{
	int ml = 0, mr = 0, mx = 0;
	if (tr != nullptr)
	{
		ml = subtreeHeight(tr->left);
		mr = subtreeHeight(tr->right);
		return 1 + (ml > mr ? ml : mr);
	}
	return 0;
}




void myBST::preorderTraversal()
{
	preorder(root);
}

void myBST::preorder(binNode *T)
{
	if (T != nullptr)
	{
		cout << T->item << ", ";
		preorder(T->left);
		preorder(T->right);
	}
}



void myBST::inorderTraversal()
{
	inorder(root);
}

void myBST::inorder(binNode *T)
{
	if (T != nullptr)
	{
		inorder(T->left);
		cout << T->item << ", ";
		inorder(T->right);
	}
}



void myBST::postorderTraversal()
{
	postorder(root);
}

void myBST::postorder(binNode *T)
{
	if (T != nullptr)
	{
		postorder(T->left);
		postorder(T->right);
		cout << T->item << ", ";

	}
}


void myBST::insertR(char x)
{
	insertRec(x, root);
}

void myBST::insertRec(char x, binNode *&T)
{
	if (T == nullptr)
	{
		T = new binNode;
		T->item = x;
		T->left = nullptr;
		T->right = nullptr;
		return;
	}
	if (x<T->item)
		insertRec(x, T->left);
	else if (x>T->item)
		insertRec(x, T->right);
}



bool myBST::search(char x)
{
	if (root == nullptr)
		return false;	
	binNode *walk = root;
	while (walk != nullptr)
	{
		if (x == walk->item)
			return true;
		if (x<walk->item)
			walk = walk->left;
		else
			walk = walk->right;
	}
	return false;
}


void myBST::remove(char ch)
{
	removeSub(root, ch);
}

void  myBST::removeSub(binNode* &T, char ch)
{
	if (T == nullptr)
		return;
	if (ch < T->item)
	{
		removeSub(T->left, ch);
		return;
	}
	if (ch > T->item)
	{
		removeSub(T->right, ch);
		return;
	}
	if (T->left == nullptr &&T->right == nullptr)   //case 1- a leaf
	{
		delete T;
		T=nullptr;
	}
	else if (T->left == nullptr && T->right != nullptr)   //case 2a- only 1 right child
	{
		binNode* temp = T;
		T = T->right;
		delete temp;
	}
	else if (T->left != nullptr && T->right == nullptr)   //case 2b- only 1 left child
	{
		binNode* temp = T;
		T = T->left;
		delete temp;
	}
	else  //general case
	{
	}
}


void myBST::drawTree()
{
	char sc[40][maxWidth];

	for (int i = 0; i<40; i++)
		for (int j = 0; j<maxWidth; j++)
			sc[i][j] = ' ';

	int h = treeHeight();
	int maxC = pow(2, h) + 1;
	if (maxC>maxWidth)
		return;
	int delta = maxC / 4;
	fillSc(sc, root, 0, maxC / 2, delta);

	for (int i = 0; i<h * 2 - 1; i++)
	{
		cout << endl;
		for (int j = 0; j<maxC; j++)
			cout << sc[i][j];
	}
	cout << endl;
}


void myBST::fillSc(char sc[40][maxWidth], binNode* T, int level, int pos, int childoffset)
{
	if (T != nullptr)
	{
		sc[level * 2][pos] = T->item;
		for (int i = pos - childoffset; i<pos + childoffset + 1; i++)
			sc[level * 2 + 1][i] = '.';
		fillSc(sc, T->left, level + 1, pos - childoffset, childoffset / 2);
		fillSc(sc, T->right, level + 1, pos + childoffset, childoffset / 2);
	}
}



int myBST::getNoNodes()
{
	return getNoNodesSubtree(root);
}
int myBST::getNoNodesSubtree(binNode *T)
{
	if (T == nullptr)
		return 0;
	if (T->left == nullptr&&T->right != nullptr)
		return 1+ getNoNodesSubtree(T->right);
	if (T->left != nullptr&&T->right == nullptr)
		return 1+ getNoNodesSubtree(T->left);
	return getNoNodesSubtree(T->left) + getNoNodesSubtree(T->right);
}