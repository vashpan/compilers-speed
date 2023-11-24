// __HEADER_BEGIN__
//
// Swift compile time test program
//

import Foundation

// __HEADER_END__

func partition__NNNN__(_ arr: inout [Int], _ start: Int, _ end: Int) -> Int {
    let pivot = arr[start]

    var count = 0
    for i in (start + 1)...end {
        if arr[i] <= pivot {
            count += 1
        }
    }

    // Giving pivot element its correct position
    let pivotIndex = start + count
    arr.swapAt(pivotIndex, start)

    // Sorting left and right parts of the pivot element
    var i = start
    var j = end

    while i < pivotIndex && j > pivotIndex {
        while arr[i] <= pivot {
            i += 1
        }

        while arr[j] > pivot {
            j -= 1
        }

        if i < pivotIndex && j > pivotIndex {
            arr.swapAt(i, j)
            i += 1
            j -= 1
        }
    }

    return pivotIndex
}

func quickSort__NNNN__(_ arr: inout [Int], _ start: Int, _ end: Int) {
    // base case
    if start >= end {
        return
    }

    // partitioning the array
    let p = partition__NNNN__(&arr, start, end)

    // Sorting the left part
    quickSort__NNNN__(&arr, start, p - 1)

    // Sorting the right part
    quickSort__NNNN__(&arr, p + 1, end)
}

// __FOOTER_BEGIN__
func printArray(_ arr: [Int]) {
    for element in arr {
        print("\(element) ", terminator: "")
    }
    
    print()
}

var arr = [9, 3, 4, 2, 1, 8]
let n = arr.count

printArray(arr)
quickSort__NNNN__(&arr, 0, n - 1)
printArray(arr)

// __FOOTER_END__