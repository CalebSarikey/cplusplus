#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

//Parentheses error detection; should be 1:1 opening:closing parentheses
//If try to pop and stack is empty or if stack still has data at end, then error, else good
//Given an expression (string), evaluate if there are matching parentheses in the expression
bool matchP(string s);

int main() {

    string S; // = "(a+b)*(7+4+x)/(2^(x+y))";

    cout << "Enter a string with parentheses to check if 1:1 opening:closing  ";
    cin >> S;
    
	if (matchP(S))
		cout << "Matching" << endl;
	else
		cout << "Parentheses error" << endl;


	cout << endl << endl;
	system("pause");
	return 0;
}

bool matchP(string s) {

	stack<char> P;

	int l = s.length();
	for (int i = 0; i < l; i++) {
		if (s[i] == '(')
			P.push(s[i]);
		if (s[i] == ')') {
			if (P.empty())
				return false;
			else
				P.pop();
		}
	}

	if (P.empty())
		return true;
	else
		return false;
}
