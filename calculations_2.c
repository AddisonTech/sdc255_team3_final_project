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
            printf("F(%2d)/F(%2d) = %.6f\n", i + 1, i, ratio);
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
