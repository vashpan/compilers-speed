// __HEADER_BEGIN__
//
// Rust compile time test program
//

// __HEADER_END__

fn partition__NNNN__(arr: &mut [i32], start: usize, end: usize) -> usize {
    let pivot = arr[start];

    let mut count = 0;
    for i in (start + 1)..=end {
        if arr[i] <= pivot {
            count += 1;
        }
    }

    // Giving pivot element its correct position
    let pivot_index = start + count;
    arr.swap(pivot_index, start);

    // Sorting left and right parts of the pivot element
    let mut i = start;
    let mut j = end;

    while i < pivot_index && j > pivot_index {
        while arr[i] <= pivot {
            i += 1;
        }

        while arr[j] > pivot {
            j -= 1;
        }

        if i < pivot_index && j > pivot_index {
            arr.swap(i, j);
            i += 1;
            j -= 1;
        }
    }

    pivot_index
}

fn quick_sort__NNNN__(arr: &mut [i32], start: usize, end: usize) {
    // base case
    if start >= end {
        return;
    }

    // partitioning the array
    let p = partition__NNNN__(arr, start, end);

    // Sorting the left part
    if let Some(end) = p.checked_sub(1) {
        quick_sort__NNNN__(arr, start, end);
    }

    // Sorting the right part
    if let Some(start) = p.checked_add(1) {
        quick_sort__NNNN__(arr, start, end);
    }
}

// __FOOTER_BEGIN__
fn print_array(arr: &[i32]) {
    for &element in arr {
        print!("{} ", element);
    }

    println!();
}

fn main() {
    let mut arr = vec![9, 3, 4, 2, 1, 8];
    let n = arr.len();

    print_array(&arr);
    quick_sort__NNNN__(&mut arr, 0, n - 1);
    print_array(&arr);
}

// __FOOTER_END__
