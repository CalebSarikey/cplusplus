#ifndef MYSTACK_H
#define MYSTACK_H

const int maxStackSize = 1000;

class myStack {
  public:
    myStack(); //constructor
    bool push(int x); //inserts an integer x into the stack; returns true if it succeeds
    int pop(); // return the element at the top of the stack after removing from the stack
    int peek(); //return the element at the top of the stack, but it does not remove it
    bool isEmpty(); //return true if the stack is empty
    bool isFull(); //return true if the stack is full
    void printStack(); //prints the stack
    int getSize(); //return size of the stack
  private:
    int data[maxStackSize]; //an array of maximum maxStackSize integer elements. used to store the data.
    int top; //index of the top of the stack
  };
  #endif
/* ———————————————————————*/
