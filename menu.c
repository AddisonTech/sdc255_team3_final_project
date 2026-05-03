/*
 * menu.c
 * Author: Torren Moore
 * Description: Menu function for Team 3 Final Project
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu() {
    int option;

    system("clear");

    printf("=== Main Menu ===\n");
    printf("1. Read File\n");
    printf("2. Write File\n");
    printf("3. Calculation 1\n");
    printf("4. Calculation 2\n");
    printf("5. Exit\n");
    printf("=================\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    return option;
}
