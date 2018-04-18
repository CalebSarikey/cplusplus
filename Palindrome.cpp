#include <iostream>  //cin, cout
#include <queue>     //for queue
#include <stack>     //for stack

using namespace std;

//A function that will determine whether an input entered from the keyboard is a palindrome
//using a stack and a queue
//A palindrome is a string reads the same forward or backward (e.g., kayak, dad, madam, sddffdds)
//The function will
//  - prompt the user to enter a phrase, and to press enter when done
//  - print "Palindrome" or "Not a palindrome" depending if the phrase is a palindrome or not
void isPalindrome();


int main()
{
	isPalindrome();
	cout<<"Try again..."<<endl;
	isPalindrome();

	system("pause");
	return 0;
}

void isPalindrome() {

	char ch;	//variable to get the characters from user input

	//stack and queue to store characters
	stack<char> s1;
	queue<char> q1;

	char s, q;	//variables to hold characters from stack & queue

	bool P = true;	//bool to determine whether palindrome or not

	cout << "Enter a phrase and press enter when you are done: ";
	//get character input from user until enter is pressed
	//push the characters one-by-one onto both the stack and queue
	while (cin.get(ch) && (ch != '\n')) {
		s1.push(ch);
		q1.push(ch);
	}

	//pop the stack and queue and compare each character
	//if any characters are different, phrase is not a palindrome
	while (!s1.empty() && !q1.empty() && (P == true)) {
		s = s1.top();
		q = q1.front();
		//if the characters are different, P is false and it is not a palindrome
		if (s != q) 
			P = false;
		//remove the characters from stack and queue
		s1.pop();
		q1.pop();
	}

	if (P == true)
		cout << "The phrase is a palindrome." << endl << endl;
	else
		cout << "The phrase is not a palindrome." << endl << endl;
}
