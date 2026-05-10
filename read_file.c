/*
 * read_file.c
 * Author: James Strohm
 * Description: Read File function for Team 3 Final Project
 */

#include <stdio.h>
#include "read_file.h"

void readFile() {
    FILE *file = fopen("output.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open output file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
