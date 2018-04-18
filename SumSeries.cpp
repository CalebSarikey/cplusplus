#include <iostream> //cin, cout
using namespace std;

//A recursive function that given a positive integer N, it will return the sum of all numbers from 1 to N.
int sumASeries(int N);

int main() {
  int N;
  
  cout << "Enter a number: ";
  cin >> N;

  cout << "The sum of the numbers from 0 to " << N << " is " << sumASeries(N) <<endl;

  return 0;
  }

int sumASeries(int N) {
  //recursive call to sum numbers from N down to 0
  //decreases N by 1 each time function is called recursively
  //once N is 0, the while loop will not execute & the function terminates
  while (N != 0)
    return sumASeries(N - 1) + N;
  return 0;
  }
