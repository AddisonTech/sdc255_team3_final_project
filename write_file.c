#include <stdio.h>
#include "write_file.h"

void writeToFile(const char *data) {
    FILE *file = fopen("output.txt", "a");

    if (file == NULL) {
        printf("Error: Could not open output file.\n");
        return;
    }

    fprintf(file, "%s\n", data);

    fclose(file);

    printf("Data written to file successfully.\n");
}
