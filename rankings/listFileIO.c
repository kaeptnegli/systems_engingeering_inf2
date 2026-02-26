#include <stdio.h>
#include "listFileIO.h"

int showFileContents(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char string_buffer[100];

    while (fscanf(fp, "%s", string_buffer) == 1){
        printf("%s\n", string_buffer);
    }
    fclose(fp);
    return 0;
}

