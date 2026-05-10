# Fibonacci Sequence (Calculation 2) Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add a Fibonacci sequence generator with golden ratio convergence as menu option 4, replacing the unimplemented `secondCalculation`.

**Architecture:** Two new files (`calculations_2.h`, `calculations_2.c`) follow the existing module pattern. `option_selector.c` and `menu.c` are updated minimally to wire in the new function. The implementation reuses `writeToFile()` from the existing write module.

**Tech Stack:** C (standard library only — `stdio.h`, `stdlib.h`, `string.h`), existing `writeToFile()` from `write_file.h`

---

### Task 1: Create `calculations_2.h`

**Files:**
- Create: `calculations_2.h`

- [ ] **Step 1: Create the header file**

```c
#ifndef CALCULATIONS_2_H
#define CALCULATIONS_2_H

void calculationTwo();

#endif
```

- [ ] **Step 2: Verify the file exists**

Run: `ls calculations_2.h`  
Expected: file listed with no error

- [ ] **Step 3: Commit**

```bash
git add calculations_2.h
git commit -m "Add calculations_2.h header"
```

---

### Task 2: Create `calculations_2.c`

**Files:**
- Create: `calculations_2.c`
- Depends on: `calculations_2.h`, `write_file.h`

- [ ] **Step 1: Create the implementation file**

```c
/*
 * calculations_2.c
 * Author: James Strohm
 * Description: Fibonacci Sequence with Golden Ratio Convergence for Team 3 Final Project
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculations_2.h"
#include "write_file.h"

void calculationTwo() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return;
    }

    long long *fib = malloc(n * sizeof(long long));
    if (fib == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    fib[0] = 1;
    if (n > 1) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("\nFibonacci Sequence (%d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld", fib[i]);
        if (i < n - 1) printf("  ");
    }
    printf("\n");

    if (n > 1) {
        printf("\nGolden Ratio Convergence (phi = 1.618033...):\n");
        for (int i = 1; i < n; i++) {
            double ratio = (double)fib[i] / fib[i - 1];
            printf("F(%d)/F(%d)%s= %.6f\n",
                   i + 1, i,
                   (i < 9) ? "   " : " ",
                   ratio);
        }
    }

    char output[512];
    snprintf(output, sizeof(output), "Fibonacci sequence of %d terms: ", n);
    for (int i = 0; i < n; i++) {
        char num[24];
        snprintf(num, sizeof(num), "%lld ", fib[i]);
        if (strlen(output) + strlen(num) < sizeof(output) - 1)
            strcat(output, num);
    }
    writeToFile(output);

    free(fib);
}
```

- [ ] **Step 2: Compile to verify no errors (do not link yet)**

Run: `gcc -c calculations_2.c -o calculations_2.o`  
Expected: No output, no errors. `calculations_2.o` created.

- [ ] **Step 3: Commit**

```bash
git add calculations_2.c
git commit -m "Add calculationTwo - Fibonacci sequence with golden ratio convergence"
```

---

### Task 3: Update `option_selector.c`

**Files:**
- Modify: `option_selector.c`

Current case 4 (lines 25-27):
```c
case 4:
    secondCalculation(0, 0);
    break;
```

Current includes (lines 7-12):
```c
#include <stdio.h>
#include "option_selector.h"
#include "menu.h"
#include "read_file.h"
#include "write_file.h"
#include "calculations.h"
```

- [ ] **Step 1: Add the new include and swap the case 4 call**

Replace the include block with:
```c
#include <stdio.h>
#include "option_selector.h"
#include "menu.h"
#include "read_file.h"
#include "write_file.h"
#include "calculations.h"
#include "calculations_2.h"
```

Replace case 4 with:
```c
case 4:
    calculationTwo();
    break;
```

- [ ] **Step 2: Compile to verify no errors**

Run: `gcc -c option_selector.c -o option_selector.o`  
Expected: No output, no errors.

- [ ] **Step 3: Commit**

```bash
git add option_selector.c
git commit -m "Wire calculationTwo into option selector (case 4)"
```

---

### Task 4: Update `menu.c`

**Files:**
- Modify: `menu.c`

Current line 20:
```c
printf("4. Calculation 2\n");
```

- [ ] **Step 1: Update the menu label**

Replace line 20 with:
```c
printf("4. Fibonacci Sequence\n");
```

- [ ] **Step 2: Commit**

```bash
git add menu.c
git commit -m "Update menu option 4 label to Fibonacci Sequence"
```

---

### Task 5: Full Compile and Manual Verification

**Files:** all `.c` files

- [ ] **Step 1: Compile the full program**

Run:
```bash
gcc -o program main.c menu.c option_selector.c read_file.c write_file.c calculations.c calculations_2.c
```
Expected: No warnings or errors. `program` (or `program.exe` on Windows) created.

- [ ] **Step 2: Run and verify — happy path (N=10)**

Run: `./program` (or `program.exe` on Windows)  
Select option 4. Enter `10`.

Expected terminal output:
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

Expected `output.txt` last line:
```
Fibonacci sequence of 10 terms: 1 1 2 3 5 8 13 21 34 55
```

- [ ] **Step 3: Verify edge case (N=1)**

Select option 4 again. Enter `1`.

Expected: Prints `1` with no convergence table (only one term, no ratio to compute).

- [ ] **Step 4: Verify edge case (N=0 or negative)**

Select option 4 again. Enter `0`.

Expected: `Please enter a positive number.` — no crash.

- [ ] **Step 5: Final commit**

```bash
git add -A
git commit -m "Fibonacci sequence with golden ratio convergence complete"
```
