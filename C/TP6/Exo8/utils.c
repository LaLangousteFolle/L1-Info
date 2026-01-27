#include "utils.h"

void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void copyArray(int *origin, int *destination, int origin_size, int destination_size)
{
    if (origin_size <= destination_size)
    {
        for (int i = 0; i < origin_size; i++)
        {
            destination[i] = origin[i];
        }
    }
    else {
    printf("tab trop petit\n");
    }
}

void addValue(int **array, int size, int value)
{
    int actual_size;
    actual_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (*array[i] != -1)
            actual_size++;
    }
    if (size > actual_size)
    {
        *array[actual_size] = value;
    }
    else
    {
        int *array1 = malloc(sizeof(int) * (size + 1));
        copyArray(*array, array1, size, size + 1);
        array1[actual_size] = value;
        *array = array1;
        free(array);
    }
}
