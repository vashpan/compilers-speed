// __HEADER_BEGIN__
//
// C compile time test program
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// __HEADER_END__

void swap__NNNN__(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int partition__NNNN__(int arr[], int start, int end) {
	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap__NNNN__(&arr[pivotIndex], &arr[start]);

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
			swap__NNNN__(&arr[i++], &arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort__NNNN__(int arr[], int start, int end) {
	// Base case
	if (start >= end)
		return;

	// Partitioning the array
	int p = partition__NNNN__(arr, start, end);

	// Sorting the left part
	quickSort__NNNN__(arr, start, p - 1);

	// Sorting the right part
	quickSort__NNNN__(arr, p + 1, end);
}

// __FOOTER_BEGIN__
void randomizeArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}

int main() {
	const int n = 6;
	int arr[n] = { 0 };
    
	srand(time(NULL));

	// __REPETITIONS_BEGIN__
	randomizeArray(arr, n);
	quickSort__NNNN__(arr, 0, n - 1);
	printArray(arr, n);
	// __REPETITIONS_END__

	return 0;
}

// __FOOTER_END__