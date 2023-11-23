// __HEADER_BEGIN__
//
// C compile time test program
//

#include <cstdlib>
#include <iostream>

using namespace std;

// __HEADER_END__

int partition__NNNN__(int arr[], int start, int end) {
	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort__NNNN__(int arr[], int start, int end) {
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition__NNNN__(arr, start, end);

	// Sorting the left part
	quickSort__NNNN__(arr, start, p - 1);

	// Sorting the right part
	quickSort__NNNN__(arr, p + 1, end);
}

// __FOOTER_BEGIN__
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;
}

int main() {
	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;
    
    printArray(arr, n);

	quickSort0001(arr, 0, n - 1);

	printArray(arr, n);

	return 0;
}

// __FOOTER_END__