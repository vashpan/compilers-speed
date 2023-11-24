// __HEADER_BEGIN__
//
// Go compile time test program
//

package main

import "fmt"

// __HEADER_END__

func partition__NNNN__(arr []int, start int, end int) int {
	pivot := arr[start]

	count := 0
	for i := start + 1; i <= end; i++ {
		if arr[i] <= pivot {
			count++
		}
	}

	// Giving pivot element its correct position
	pivotIndex := start + count
	arr[pivotIndex], arr[start] = arr[start], arr[pivotIndex]

	// Sorting left and right parts of the pivot element
	i, j := start, end

	for i < pivotIndex && j > pivotIndex {
		for arr[i] <= pivot {
			i++
		}

		for arr[j] > pivot {
			j--
		}

		if i < pivotIndex && j > pivotIndex {
			arr[i], arr[j] = arr[j], arr[i]
			i++
			j--
		}
	}

	return pivotIndex
}

func quickSort__NNNN__(arr []int, start int, end int) {
	// base case
	if start >= end {
		return
	}

	// partitioning the array
	p := partition__NNNN__(arr, start, end)

	// Sorting the left part
	quickSort__NNNN__(arr, start, p-1)

	// Sorting the right part
	quickSort__NNNN__(arr, p+1, end)
}

// __FOOTER_BEGIN__
func printArray(arr []int) {
	for _, element := range arr {
		fmt.Printf("%d ", element)
	}

	fmt.Println()
}

func main() {
	arr := []int{9, 3, 4, 2, 1, 8}
	n := len(arr)

	printArray(arr)
	quickSort__NNNN__(arr, 0, n-1)
	printArray(arr)
}
// __FOOTER_END__