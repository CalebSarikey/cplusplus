#include <iostream> //cin, cout
#include <queue> //for queue
#include <stack> //for stack

using namespace std;

void randomFillArray(double A[], int size);
void printArray(const double A[], int size);
//A recursive function that will compute the sum of a given array of doubles
double sumArrayR(double A[], int size);

int main() {
  double A[100];
  int size=100;

  randomFillArray(A,size);

  cout<<"The array given is : "<<endl;
  printArray(A, size);

  cout<<"The sum of the array is "<<sumArrayR(A,size)<<endl;

  return 0;
}

double sumArrayR(double A[], int size) {
  //terminate when size is 0. all elements have been added at this point.
  if (size <= 0)
    return 0;
  //recursive call to add elements starting from the last element
  return sumArrayR(A, size - 1) + A[size - 1];
}

void randomFillArray(double A[], int size) {
  A[0]=rand()%11;
  for (int i=1; i<size; i++) {
    A[i]=A[i-1]+rand()%21;
  }
}

void printArray(const double A[], int size) {
  for (int i=0; i<size-1; i++)
    cout<<A[i]<<", ";
  cout<<A[size-1]<<";"<<endl;
}
