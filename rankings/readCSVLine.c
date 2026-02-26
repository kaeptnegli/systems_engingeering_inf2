#include <stdio.h>
#include "readCSVLine.h"

char* readCSVLine(const char *filename, char *buffer, int str_len, int *linesCount) {
   static FILE *fd = NULL;

   if (!fd) {
      fd = fopen(filename, "r");
      if (!fd) {
         printf("Error opening file %s\n", filename);
         return NULL;
      }
   }

   char* line = fgets(buffer, str_len, fd);

   if (!line) {
      fclose(fd);
      fd = NULL;
   } else {
      (*linesCount)++;
      printf("Read line %d from File %s: %s", *linesCount, filename, line);
   }

   return line;
}
