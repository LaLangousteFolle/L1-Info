#ifndef UTILS
#define UTILS
#include <stdio.h>
#include <stdlib.h>
void displayArray(int *array, int size);
void copyArray(int *origin, int *destination, int origin_size, int destination_size);
void addValue(int **array, int size, int value);
#endif