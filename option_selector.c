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

void mainLoop(int option) {
    switch(option) {
        case 1:
            readFile();
            break;
        case 2:
            writeToFile("Team 3 Final Project output");
            break;
        case 3:
            firstCalculation(0, 0);
            break;
        case 4:
            secondCalculation(0, 0);
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}
