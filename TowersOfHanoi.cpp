#include <iostream>
#include <cstdlib>

using namespace std;

void solve_toh(int n, char start_peg, char target_peg, char spare_peg);
//Solves, recursively, the Towers of Hanoi Puzzle for n disks.
//The disks begin on start_peg. The goal is to move them - legally,
//of course - to target_peg, using spare_peg as needed.

int main () {
  int my_n;
  char start, target, spare;

  cout << "Enter a positive integer (0 or negative to quit): ";
  cin >> my_n;

  while (my_n > 0)
  {
    cout << endl;
    cout << "Enter a permutation of {A,B,C} indicating, in order," << endl;
    cout << "the starting peg, the target peg, and the spare peg: ";
    cin >> start;
    cin >> target;
    cin >> spare;
    cout << endl;
    cout << "Here are the moves required to solve the puzzle: " << endl;
    solve_toh(my_n,start,target, spare);
    cout << endl << endl;
    cout << "Enter the next positive integer: ";
    cin >> my_n;
  }

  cout << endl;
  system("pause");
  return 0;
}

void solve_toh(int n, char start_peg, char target_peg, char spare_peg) {
  if (n == 1){
    //move the 1 disc to the target
    cout << "Move disk 1 from " << start_peg << " to " << target_peg << ". " << endl;
  }
  else {
    //recursive call
    solve_toh(n-1, start_peg, target_peg, spare_peg);
    cout << "Move disk " << n << " from " << start_peg << " to " << target_peg << ". " << endl;
    solve_toh(n-1, spare_peg, target_peg, start_peg);
    } 
  }
