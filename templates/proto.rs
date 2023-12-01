// __HEADER_BEGIN__
//
// Rust compile time test program
//

#![allow(arithmetic_overflow)]
#![allow(non_snake_case)]

use std::time::{SystemTime, UNIX_EPOCH};

// Simple random generator as Rust doesn't seem to have it in its standard lib (?)
struct Rand {
    seed: i64,
    a: i64,
    c: i64,
    m: i64,
}

impl Rand {
    fn new() -> Self {
        // Get the current time in nanoseconds as a seed
        let nanos = SystemTime::now()
                .duration_since(UNIX_EPOCH)
                .expect("Time went backwards")
                .as_nanos();
        
        // "nanos" i a 128 bit, to avoid overflow just cut it to 16 bits
        let seed = (nanos & 0xFFFF) as i64;

        Rand { 
            seed: seed as i64,
            a: 16_807,
            c: 0,
            m: 2_147_483_647
        }
    }

    fn next(&mut self) -> i32 {
        let seed = self.seed;
        let a = self.a;
        let c = self.c;
        let m = self.m;
        self.seed = (a * seed + c) % m;

        (self.seed & 0xFFFFFFFF) as i32
    }
}

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
fn randomize_array(arr: &mut [i32], rng: &mut Rand) {
    for i in arr {
        *i = rng.next() % 10;
    }
}

fn print_array(arr: &[i32]) {
    for &element in arr {
        print!("{} ", element);
    }

    println!();
}

fn main() {
    const N: usize = 6; 
    let mut arr = vec![0; N];

    let mut rng = Rand::new();

    // __REPETITIONS_BEGIN__
    randomize_array(&mut arr, &mut rng);
    quick_sort__NNNN__(&mut arr, 0, N - 1);
    print_array(&arr);
    // __REPETITIONS_END__
}

// __FOOTER_END__
