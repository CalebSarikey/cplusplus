#include "myStack.h"
#include <iostream>

using namespace std;

myStack::myStack() {
  top = -1;
}

bool myStack::push(int x) {
  if (top < maxStackSize) {
    data[top + 1] = x;
    top++;
    return true;
  }
  else
    return false;
  }

void myStack::printStack() {
  for (int i = 0; i <= top; i++)
    cout << data[i] << ", ";
  cout << endl;
}

bool myStack::isEmpty() {
  return top < 0;
}

bool myStack::isFull() {
  return top >= maxStackSize;
}

int myStack::pop() {
  int temp = -999999;
  if (top >= 0) {
    temp = data[top];
    top--;
  }
return temp;
}

int myStack::peek() {
  return data[top];
}

int myStack::getSize() {
  return (top + 1);
}
