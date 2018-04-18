#pragma once

struct binNode
{
	char item;    //this is the "information" the node contains
	binNode *left;  //pointer (link) to left subtree
	binNode *right; //pointer to right subtree
};

const int maxWidth = 257;

class myBST
{
public:
	myBST();         //constructor (initialize the tree)
	void insert(char); //insert using iterative approach
	void insertR(char); //insert using recursive approach
	bool search(char);     //search for the a value
	void remove(char);    //remove char

	void preorderTraversal();   //inorder traversal 
	void inorderTraversal();   //inorder traversal 
	void postorderTraversal(); //postorder traversal
	int treeHeight();
	//a function that returns the number of nodes in a tree
	int getNoNodes();

	//drawing functions
	void drawTree();

private:
	binNode *root;

	int getNoNodesSubtree(binNode *);

	void preorder(binNode*);    //helper function for preorder traversal
	void inorder(binNode*);    //helper function for inorder traversal
	void postorder(binNode*);  //helper function for postorder traversal
	void insertRec(char, binNode*&); //helper function for recursive insertion
	int subtreeHeight(binNode*);     //helper function for tree height
	void fillSc(char[40][maxWidth], binNode*, int, int, int);  //helper function for drawing
	void removeSub(binNode*&, char); //helper function for remove


};
