#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
/*---------------------------------------------------------------------*/
//Given 2 stacks of doubles (S1 and S1), return a stack that is S2 stacked on top of S1
//Ex) If S1={8, 10, 7} and S2={4,6}, then S3 should return {8, 10, 7, 4, 6}
stack<double> combineStacks(stack<double> S1, stack<double> S2);
/*---------------------------------------------------------------------*/
int main(){
stack<double> S1, S2, S3;
S1.push(8);
S1.push(10);
S1.push(7);
S2.push(4);
S2.push(6);
S3 = combineStacks(S1, S2);

//display stack in reverse order
for(int i=0; i<5; i++){
  double t = S3.top();
  cout << t << " ";
  S3.pop();
}

cout << endl << endl;
return 0;
}

stack<double> combineStacks(stack<double> S1, stack<double> S2) {
  //Use temp to reverse. Start with S3 equal to S1
  stack<double> S3=S1, tempStack;

  while (!S2.empty()) {
    //Get top element of S2, remove/pop top element, put it in temp
    double v = S2.top();
    S2.pop();
    tempStack.push(v);
  }

//empty tempStack(which is in reverse order currently) into S3 (which already contains S1 in order)
while (!tempStack.empty()) {
  double v = tempStack.top();
  tempStack.pop();
  S3.push(v);
  }

return S3;
}
