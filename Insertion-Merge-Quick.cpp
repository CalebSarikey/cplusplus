#include <iostream>

using namespace std;

struct empType
{
	int ID;
	double Score;
};

void populateArray(empType A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i].ID = rand() % 10001;
		A[i].Score = rand() % 101;
	}
};

void printArray(empType A[], int n)
{
	cout << "ID\tScore\n";
	for (int i = 0; i < n; i++)
	{
		cout << A[i].ID << "\t" << A[i].Score << endl;
	}
}

void copyArray(empType A[], empType B[], int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = B[i];
	}
};

int insertionSort(empType A[], int first, int last);
int mergeSort(empType A[], int first, int last);
void merge(empType E[], int first, int mid, int last);
int quickSort(empType A[], int first, int last);
int partition(empType A[], int first, int last);
void swap(int &x, int &y);


int main()
{
	int M = 100;
	empType *A, *B, *C;
	A = new empType[M];
	B = new empType[M];
	C = new empType[M];

	populateArray(A, M);
	copyArray(B, A, M);
	copyArray(C, A, M);
	
	
	cout << "Testing Insertion Sort ..." << endl;
	cout << "Array before sorting:\n";
	printArray(A, M);
	int ti = insertionSort(A, 0, M - 1);
	cout << "Array after sorting:\n";
	printArray(A, M);
	cout << "For size = " << M << ", Insertion Sort performed " << ti << " comparisons\n";

	system("pause");
	system("cls");
	
	
	
	cout << "Testing Merge Sort ..." << endl;
	cout << "Array before sorting:\n";
	printArray(B, M);
	int tm = mergeSort(B, 0, M - 1);
	cout << "Array after sorting:\n";
	printArray(B, M);
	cout << "For size = " << M << ", Merge Sort performed " << tm << " comparisons\n";

	system("pause");
	system("cls");

	
	cout << "Testing Quick Sort ..." << endl;
	cout << "Array before sorting:\n";
	printArray(C, M);
	int tq = quickSort(C, 0, M - 1);
	cout << "Array after sorting:\n";
	printArray(C, M);
	cout << "For size = " << M << ", Quick Sort performed " << tq << " comparisons\n";
	
	system("pause");
	system("cls");

	system("pause");

	
	return 0;
}

int insertionSort(empType A[], int first, int last) {
	int counter = 0;

	for (int unsorted = (first + 1); unsorted <= last; unsorted++) {
		empType nextItem = A[unsorted];
		int loc = unsorted;
		while ((loc > 0) && (A[loc - 1].ID > nextItem.ID)) {
			A[loc] = A[loc - 1];
			loc--;
			counter+=2;
		}
		A[loc] = nextItem;
	}
	return counter;
}


const int SIZE = 100;	//for temp array in merge
int mergeCounter = 0;	//to count comparisons

int mergeSort(empType A[], int first, int last) {
	mergeCounter++;	//increment counter for if comparison
	if (first < last) {
		//sort each half
		int mid = first + (last - first) / 2;	//index of midpoint
		//sort left half
		mergeSort(A, first, mid);
		//sort right half
		mergeSort(A, mid + 1, last);
		//merge the two halves
		merge(A, first, mid, last);
	}

	return mergeCounter;
}

void merge(empType A[], int first, int mid, int last) {
	empType tempA[SIZE]; // Temporary array

//Initialize indices of subarrays
	int first1 = first; // Beginning of first subarray
	int last1 = mid; // End of first subarray
	int first2 = mid + 1; // Beginning of second subarray
	int last2 = last; // End of second subarray
					  
//While subarrays are not empty, copy smaller item into temp
	int index = first1; // Next available location in temp
	while ((first1 <= last1) && (first2 <= last2))
	{
		//mergeCounter+=2;	//increment counter by 2 for while comparisons
		// At this point, tempA[first..index-1] is in order
		if (A[first1].ID <= A[first2].ID)
		{
			mergeCounter++;	//incrememnt counter for if comparison
			tempA[index] = A[first1];
			first1++;
		}
		else
		{
			tempA[index] = A[first2];
			first2++;
		}
		index++;
	}

//Finish the first subarray
	while (first1 <= last1)
	{
		mergeCounter++; //increment counter for while loop comparison
		// At this point, tempA[first..index-1] is in order
		tempA[index] = A[first1];
		first1++;
		index++;
	} 
// Finish the second subarray
	while (first2 <= last2)
	{
		mergeCounter++;//increment counter for while loop comparison
		// At this point, tempA[first..index-1] is in order
		tempA[index] = A[first2];
		first2++;
		index++;
	}
	
// Copy back into A
	for (index = first; index <= last; index++)
		A[index] = tempA[index];
} 


int Qcount = 0;	//to count quicksort comparisons

int quickSort(empType A[], int first, int last){

	int pivotPoint;

	if(first < last){
		//partition 
		pivotPoint = partition(A, first, last);
		//sort subarrays
		quickSort(A, first, pivotPoint - 1);
		quickSort(A, pivotPoint + 1, last);
		}

		return Qcount;
}

int partition(empType A[], int first, int last) {

	int pivotValue, pivotIndex, mid;

	mid = (first + last) / 2;	//mid index
	swap(A[first], A[mid]);
	//set pivot index & get value
	pivotIndex = first;
	pivotValue = A[first].ID;

	for (int scan = first + 1; scan <= last; scan++) {
		if (A[scan].ID < pivotValue) {
			Qcount++;	//increment counter for if comparison
			pivotIndex++;
			swap(A[pivotIndex], A[scan]);
		}
	}
	swap(A[first], A[pivotIndex]);
	return pivotIndex;
}

//to swap for quickSort
void swap(empType &x, empType &y)
{
	empType temp = x;
	x = y;
	y = temp;
}
