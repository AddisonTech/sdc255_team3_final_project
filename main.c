/*
 * main.c
 * Author: Addison Smith
 * Description: Main integration function for Team 3 Final Project
 */

#include <stdio.h>
#include "menu.h"
#include "option_selector.h"

int main() {
    int option;

    do {
        option = menu();
        mainLoop(option);
    } while (option != 5);

    printf("Program ended.\n");

    return 0;
}
