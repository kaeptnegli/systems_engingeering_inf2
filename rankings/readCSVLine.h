#ifndef READCSVLINE_H
#define READCSVLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readCSVLine(const char *filename, char *buffer, int str_len, int *linesCount);

#endif
