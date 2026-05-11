/*
 * option_selector.c
 * Author: Torren Moore
 * Description: Option Selector function for Team 3 Final Project
 */

#include <stdio.h>
#include "option_selector.h"
#include "menu.h"
#include "read_file.h"
#include "write_file.h"
#include "calculations.h"
#include "calculations_2.h"

void pauseScreen() {
    int ch;

    printf("\nPress Enter to return to the menu...");
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
    getchar();
}

void mainLoop(int option) {
    double num1;
    double num2;
    double result;

    switch(option) {
        case 1:
            readFile();
            pauseScreen();
            break;

        case 2:
            writeToFile("Team 3 Final Project output");
            pauseScreen();
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%lf", &num1);

            printf("Enter second number: ");
            scanf("%lf", &num2);

            result = calculationOne(num1, num2);

            printf("Calculation 1 average result: %.2f\n", result);
            pauseScreen();
            break;

        case 4:
            calculationTwo();
            pauseScreen();
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid option. Please try again.\n");
            pauseScreen();
            break;
    }
}
