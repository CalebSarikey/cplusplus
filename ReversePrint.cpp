#include <iostream> //cin, cout
#include <queue> //for queue
#include <stack> //for stack

using namespace std;

void randomFillArray(double A[], int size);
void printArray(const double A[], int size);

//A recursive function that given an array of doubles, it will print its entries backwards
void printArrayBackwards(double A[], int size);

int main() {
  double A[100];
  int size=100;
  randomFillArray(A, size);

  cout << "Original array is: " << endl;
  printArray(A, size);

  cout << endl << endl;

  cout << "Array printed backwards is: " << endl;
  printArrayBackwards(A, size);

  return 0;
}

void printArrayBackwards(double A[], int size) {
  //print the first element of the array last
  if (size == 1) {
  cout << A[0] << " " << endl;
  }
  //recursive call to print the last element of the array
  //and to decrease size each time until size is 1
  else {
    cout << A[size - 1] << ", ";
    printArrayBackwards(A, size - 1);
  }
}

void randomFillArray(double A[], int size) {
  A[0]=rand()%11;
  for (int i=1; i<size; i++) {
    A[i] = A[i-1] + rand() % 21;
    }
  }

void printArray(const double A[], int size) {
  for (int i=0; i<size-1; i++)
    cout << A[i] << ", ";
  cout << A[size-1] << ";" << endl;
}
