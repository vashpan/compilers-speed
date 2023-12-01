// __HEADER_BEGIN__
//
// Go compile time test program
//

package main

import (
	"fmt"
	"math/rand"
	"time"
)

// __HEADER_END__

func swap__NNNN__(a *int, b *int) {
	c := *a
	*a = *b
	*b = c
}

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
	swap__NNNN__(&arr[pivotIndex], &arr[start])

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
			swap__NNNN__(&arr[i], &arr[j])
			i++
			j--
		}
	}

	return pivotIndex
}

func quickSort__NNNN__(arr []int, start int, end int) {
	// Base case
	if start >= end {
		return
	}

	// Partitioning the array
	p := partition__NNNN__(arr, start, end)

	// Sorting the left part
	quickSort__NNNN__(arr, start, p-1)

	// Sorting the right part
	quickSort__NNNN__(arr, p+1, end)
}

// __FOOTER_BEGIN__
func randomizeArray(arr []int, size int) {
	for i := 0; i < size; i++ {
		arr[i] = rand.Intn(10)
	}
}

func printArray(arr []int, size int) {
	for i := 0; i < size; i++ {
		fmt.Printf("%d ", arr[i])
	}

	fmt.Println()
}

func main() {
	const n = 6
	arr := make([]int, n)

	rand.Seed(time.Now().UnixNano())

	// __REPETITIONS_BEGIN__
	randomizeArray(arr, n)
	quickSort__NNNN__(arr, 0, n-1)
	printArray(arr, n)
	// __REPETITIONS_END__

}

// __FOOTER_END__