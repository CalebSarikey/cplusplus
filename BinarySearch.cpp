// BinarySearch.cpp
// Recursive Binary Search

#include <iostream> //cin, cout
#include <queue> //for queue
#include <stack> //for stack

using namespace std;

void randomFillArray(double A[], int size);     //to fill array with random numbers in ascending order
void printArray(const double A[], int size);    //to print contents of array

//A recursive function that given a sorted array of real numbers, and a value x
//it will use binary search to determine if x is in the array
//The function will return the index of x if x is in the array and -1 if it is not
//Let:
//'first' be the index of the first element in the array
//'last' be the index of the last element in the array and x the value searched for
int binSearchRec(double A[], double x, int first, int last);

int main() {
    double A[200];
    int size=100;
    int val1,val2;
    
    randomFillArray(A,size);
    
    cout << "The array given is : " << endl;
    printArray(A, size);
    
    cout << "Enter value you want to search for : ";
    cin >> val1;
    cout << "Searching for " << val1 << endl;
    int ind1 = binSearchRec(A, val1,0,size-1);
    if (ind1 >= 0)
        cout << "Found at position " << ind1 << "." <<endl;
    else
        cout << "Not found." << endl;
    
    cout << "Enter value you want to search for : ";
    cin >> val2;
    cout << "Searching for " << val2 << endl;
    int ind2 = binSearchRec(A, val2,0,size-1);
    if (ind2>=0)
        cout << "Found at position " << ind2 << "." << endl;
    else
        cout << "Not found." << endl;
    
 // system("pause");
    return 0;
}


int binSearchRec(double A[], double x, int first, int last) {
    int low = first; //set first to the lowest index boundary for the search
    int high = last; //set high to the highest index boundary for the search
    int mid; //to hold the middle index
    bool found = false; //indicates whether or not x has been found. initially, found is false
    
    //if low is greater than high or if high is less than low,
    //the search would go out of bounds
    //this means the element was not found
    while ((low <= high) && (!found)) {
        //average the low and high to get the middle index
        mid = (low + high) / 2;
        //if x is found at the middle position, return x
        if (x == A[mid])
            found = true;
        //if x is less than the value at the mid index position, recursively search from low to mid-1
        else if (x < A[mid])
            return binSearchRec(A, x, low, mid - 1);
        //if x is greater than the value at the mid index position, recursively search from mid+1 to high
        else
            return binSearchRec(A, x, mid + 1, high);
    }
    //if x was found, return it's position
    //else, return -1 meaning x was not found
    if (found)
        return mid;
    else
        return -1;
}


void randomFillArray(double A[], int size) {
    A[0]=rand()%11;
    for (int i=1; i<size; i++)
    {
        A[i]=A[i-1]+rand()%21;
    }
}

void printArray(const double A[], int size) {
    for (int i=0; i<size-1; i++)
        cout<<A[i]<<", ";
    cout << A[size-1] << ";" << endl;
}
