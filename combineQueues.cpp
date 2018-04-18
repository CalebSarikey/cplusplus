#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
/* ------------------------------------------------------------- */
//Given 2 queue's of integers (Q1 & Q2), return a 3rd queue which is a combination of Q1 and Q2 by alternating elements
//Ex) If Q1={10, 20, -5} and Q2={35, 45, 155), then Q3={10, 35, 20, 45, -5, 155}
queue<int> combineQueues(queue<int> Q1, queue<int> Q2);
/* ------------------------------------------------------------- */
int main() {
queue<int> Q1, Q2, Q3;
Q1.push(10);
Q1.push(20);
Q1.push(-5);
Q2.push(35);
Q2.push(45);
Q2.push(155);
Q3 = combineQueues(Q1, Q2);

//display new queue
for(int i=0; i<6; i++){
  int x = Q3.front();
  cout << x << " ";
  Q3.pop();
  }

cout << endl << endl;
return 0;
}
/* ------------------------------------------------------------- */
queue<int> combineQueues(queue<int> Q1, queue<int> Q2) {
  queue<int> Q3;
//while both queues have elements in them
while ((!Q1.empty()) && (!Q2.empty())) {
//Get element in front of queues
  int x = Q1.front();
  int y = Q2.front();
//remove elements
  Q1.pop();
  Q2.pop();
//push into Q3
  Q3.push(x);
  Q3.push(y);
}
//case for different number of elements in Q1&Q2. dump rest of elements into Q3
while (!Q1.empty()) {
  int x = Q1.front();
  Q1.pop();
  Q3.push(x);
}

while (!Q2.empty()) {
  int x = Q2.front();
  Q2.pop();
  Q3.push(x);
}

return Q3;
}
