// Caleb Sarikey - CSIT 441: Assignment 3, Question 5.2.10

#include <iostream>
#include <time.h>
using namespace std;

//struct to hold data
struct empType{
	int ID;
	double Score;
};

// populates array A[] with n random elements
void populateArray(empType A[], int n){
	for (int i = 0; i < n; i++){
		A[i].ID = rand() % 10001;
		A[i].Score = rand() % 101;
	}
};

//prints n elements of array A[]
void printArray(empType A[], int n){
	cout << "ID\tScore\n";
	for (int i = 0; i < n; i++){
		cout << A[i].ID << "\t" << A[i].Score << endl;
	}
}

/* sorts array A[] in ascending order and returns
   a counter of the number of comparisons made	*/
int quickSort(empType A[], int first, int last);
int partition(empType A[], int first, int last, int &count);

/*------------------------------------------------------------------------------*/
int main(){

	srand(time(0));	//seed random number generator

	//to hold test sizes
	int M[4] = { 100, 1000, 10000, 100000 };

	//to store average number of ops and average execution time
	int avgOps, avgTime;

	cout << "QuickSort Analysis: Average Comparisons and Execution Time\n";
	cout << "Calculated over 10 iterations for each n = {100, 1000, 10000, 100000}\n\n";
	cout << "Input Size\tAverage Comparisons\tAverage Time" << endl;

	//repeat for 4 test sizes
	for(int k=0; k<4; k++){
		avgOps = 0;
		avgTime = 0;

		//repeat 10 times and take average
		for(int i=0; i<10; i++){
			clock_t ms;	//to get execution time
		
			//allocate array of size M[i]
			empType *A;
			A = new empType[M[k]];

			// randomaly populate array
			populateArray(A, M[k]);

			//cout << "Array before sorting:\n";
			//printArray(A, M[i]);

			ms = clock();
			int ops = quickSort(A, 0, M[k] - 1);
			ms = clock() - ms;

			//cout << "Array after Quick Sort:\n";
			//printArray(A, M[i]);

			/* statement below prints ops and time for each iteration */
			//cout << "n = " << M[k] << " \t " << ops << " \t\t " << ms << "ms \n";
			avgOps += ops;
			avgTime += ms;
		}
		//calculate averages and display
		avgOps = avgOps / 10;
		avgTime = avgTime / 10;
		cout << "n = " << M[k] << " \t " << avgOps << " \t\t\t " << avgTime << "ms \n\n";
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
/*------------------------------------------------------------------------------*/
int quickSort(empType A[], int first, int last) {

	int count = 0;	//to count comparisons
	int pivotPoint;

	if (first < last) {
		//partition 
		pivotPoint = partition(A, first, last, count);
		//sort subarrays
		quickSort(A, first, pivotPoint - 1);
		quickSort(A, pivotPoint + 1, last);
	}
	return count;
}

int partition(empType A[], int first, int last, int &count) {

	int pivotValue, pivotIndex, mid;

	mid = (first + last) / 2;
	swap(A[first], A[mid]);
	//set pivot index & get value
	pivotIndex = first;
	pivotValue = A[first].ID;

	for (int scan = first + 1; scan <= last; scan++) {
		if (A[scan].ID < pivotValue) {
			count++;	//increment counter for if comparison
			pivotIndex++;
			swap(A[pivotIndex], A[scan]);
		}
	}
	swap(A[first], A[pivotIndex]);
	return pivotIndex;
}

