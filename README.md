# Compilers speed test

## Summary

Remember how old Borland tools showed speed of compilation? I would like to check that for modern compilers!

Right now following languages are supported: **C, C++, Go, Rust, Swift**. Feel free to add yours, pull requests are welcome. You'll find instructions [below](#adding-new-languages) how to do that.

Right now it's focused on languages that compiles directly to machine code, to maintain some comparability between them, but it would be interesting comparison to add VM-based languages as well (like Java or C#).

## Approach

Each language has "quick sort" algorithm implemented, which is then duplicated N-times to achieve roughly 100,000 lines in a single source file.

This is rather naive approach and much more factors could affect compiling speed, but it could give us a rough estimate and comparison point.

## Results

All results compared to baseline, which is good-old C language.

| Language | Debug Build Time (s)  | Release Build Time (s) |
|----------|----------------------:|-----------------------:|
| **C**    |      **0.883 (100%)** |      **13.430 (100%)** |
| C++      |      1.120 (126.84%)  |       14.370 (107.00%) |
| Go       |      0.410 (46.43%)   |         0.410 (3.05%)  |
| Rust     |      1.790 (202.72%)  |         1.700 (12.66%) |
| Swift    |     10.780 (1220.83%) |       23.870 (177.74%) |

*Measured on MacBook Pro 14-inch (2021) with Apple M1 Pro*

## Performing tests

### C

You can use either GCC or clang compiler, I used clang, for sure there'll be differences.

For debug:
```
$ time clang -o test test.c 
```

For release:
```
$ time clang -O3 -o test test.c 
```

### C++

You can use either GCC or clang compiler, I used clang, for sure there'll be differences.

For debug:
```
$ time clang++ -o test test.cpp 
```

For release:
```
$ time clang++ -O3 -o test test.cpp 
```

### Go

Official Go compiler is used. What's interesting, AFAIK there's no specific "release" mode for Go.

```
$ time go build test.go
```

### Rust

Official Rust compiler is used. `--allow unused` flag is used to get rid of warnings related to unused functions.

For debug:
```
$ time rustc --allow unused -o test test.rs
```

For release:
```
$ time rustc --allow unused -O -o test test.rs
```

### Swift

Official Swift SDK is used.

For debug:
```
$ time swiftc -o test test.swift
```

For release:
```
$ time swiftc -O -o test test.swift
```

## Adding new languages

New languages can be added relatively easily, when in doubt, check sources of other languages. It would be nice to add few more compiled languages like: D, Zig or even Pascal.

Interesting compare point would also be to check languages compiled (usually) to bytecode: Java, C#.

Here's the procedure of adding new language to the suite:

1. Create a new `proto.(lang_ext)` in `templates` folder using one of the existing ones as a base
2. Remember to properly use "markings" in the file (`__HEADER_BEGIN/END__`, `__NNNN__` etc.)
3. Make sure it properly compiles and run
4. Use `source_multiplier.py` script to generate a new test file. Tune number of repetitions to create a file that will be roughly 100k lines of code in size.
5. Make sure it properly compiles and run
6. Test compile speed (for example: using `time` command in UNIX-like systems) in both release & debug
7. Update [this section](#performing-tests) of `README.md` with instructions how to build & run compiler for given language