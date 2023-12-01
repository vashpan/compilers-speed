// __HEADER_BEGIN__
//
// C++ compile time test program
//

#include <iostream>
#include <vector>
#include <random> // for std::default_random_engine and std::uniform_int_distribution

// __HEADER_END__

int partition__NNNN__(std::vector<int>& arr, int start, int end) {
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

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
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort__NNNN__(std::vector<int>& arr, int start, int end) {
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
std::vector<int> randomizeArray(std::vector<int>& arr, int size) {
	arr.clear();
	arr.resize(size);

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 9);

    for (int& num : arr) {
        num = distribution(generator);
    }

    return arr;
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

int main() {
    const int n = 6;
	std::vector<int> arr(n);

    // __REPETITIONS_BEGIN__
    randomizeArray(arr, n);
    quickSort__NNNN__(arr, 0, n - 1);
    printArray(arr);
    // __REPETITIONS_END__

    return 0;
}

// __FOOTER_END__
