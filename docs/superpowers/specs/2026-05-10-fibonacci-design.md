# Fibonacci Sequence Feature — Design Spec
**Date:** 2026-05-10  
**Author:** James Strohm  

## Overview

Add a Fibonacci Sequence generator as menu option 4, replacing the unimplemented `secondCalculation`. The feature prints the sequence up to N terms and shows golden ratio convergence (ratio of consecutive terms approaching φ = 1.618033...). Results are also written to `output.txt`.

## New Files

### `calculations_2.h`
- Include guard: `CALCULATIONS_2_H`
- Declares: `void calculationTwo()`

### `calculations_2.c`
- Prompts user for number of terms N
- Computes sequence iteratively using an array
- Prints sequence in a single row
- Prints a convergence table: each F(i)/F(i-1) ratio alongside φ
- Calls `writeToFile()` with a string of the form `"Fibonacci sequence of N terms: 1 1 2 3 5 ..."` to append to `output.txt`

## Modified Files

| File | Change |
|---|---|
| `menu.c` | Rename option 4 label from "Calculation 2" to "Fibonacci Sequence" |
| `option_selector.c` | Add `#include "calculations_2.h"`, swap case 4 from `secondCalculation(0, 0)` to `calculationTwo()` |

## Files Unchanged

`main.c`, `calculations.c`, `calculations.h`, `read_file.c`, `read_file.h`, `write_file.c`, `write_file.h`

## Expected Output (example, N=10)

```
Enter number of terms: 10

Fibonacci Sequence (10 terms):
1  1  2  3  5  8  13  21  34  55

Golden Ratio Convergence (phi = 1.618033...):
F(2)/F(1)   = 1.000000
F(3)/F(2)   = 2.000000
F(4)/F(3)   = 1.500000
F(5)/F(4)   = 1.666667
F(6)/F(5)   = 1.600000
F(7)/F(6)   = 1.625000
F(8)/F(7)   = 1.615385
F(9)/F(8)   = 1.619048
F(10)/F(9)  = 1.617647
```

## Side Effects Fixed

`option_selector.c` was calling `secondCalculation(0, 0)` which was never declared — a compile error. This is resolved by replacing the call with `calculationTwo()`.

## Constraints

- No changes to `main.c` (exit remains option 5)
- `writeToFile()` is reused as-is — no changes to write module
- Follows existing module pattern: snake_case filenames, include guards, same error handling style
