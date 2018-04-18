#include <iostream>

using namespace std;

//print an array of doubles
void printArray(double A[], int N);

//helper function
void rebuildHeap(double A[], int N, int i) {
	//find largest between root and left and right children
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < N && A[left] > A[largest])
		largest = left;

	if (right < N && A[right] > A[largest])
		largest = right;

	//If root is not largest, swap A[i] with largest and rebuild heap 
	if (largest != i) {
		swap(A[i], A[largest]);
		rebuildHeap(A, N, largest);
	}
}

//build a maxheap with rebuildHeap helper
void buildHeap(double A[], int N) {
	for (int i = N / 2 - 1; i >= 0; i--) {
		rebuildHeap(A, N, i);
	}
	cout << "Heap array:  ";
	printArray(A, N);
}

//sort maxheap
void sortFromHeap(double A[], int N) {
	for (int i = N - 1; i >= 0; i--) {
		swap(A[0], A[i]);
		//rebuild to put highest element at root
		rebuildHeap(A, i, 0);
	}
}

//main heap sort
void heapSort(double A[], int N) {
	buildHeap(A, N);
	sortFromHeap(A, N);
}

//driver to test program with an array of 10 doubles
int main() {
	const int N = 10;
	double A[N] = {12, 9, 55, 66, 35, 10, 99, 75, 44, 3};

	cout << "Original array:  ";
	printArray(A, N);

	heapSort(A, N);

	cout << "Array after heapSort:  ";
	printArray(A, N);

	cout << endl;
	system("pause");
	return 0;
}

void printArray(double A[], int N) {
	for (int i = 0; i<N; i++)
		cout << A[i] << " ";
	cout << endl << endl;
}