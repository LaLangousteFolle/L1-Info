#include "utils.h"
int     main(void)
{
    int *array1 = malloc(sizeof(int) * 5);
    int *array2 = malloc(sizeof(int) * 7);
    for (int i = 0; i < 5; i++)
        array1[i] = -1;
    for (int i = 0; i < 7; i++)
        array2[i] = -1;
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;
    array1[3] = 4;
    array1[4] = 5;
    //displayArray(array1, 5);
    //displayArray(array2, 7);
    copyArray(array1, array2, 5, 7);
    displayArray(array1, 5);
    displayArray(array2, 7);
    addValue(&array2, 7, 15);
    addValue(&array1, 5, 15);
    displayArray(array1, 5);
    displayArray(array2, 7);
    return(0);
}
