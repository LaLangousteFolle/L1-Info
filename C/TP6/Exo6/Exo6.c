#include "Census.h"
#include <stdlib.h>

void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

Census createCensus(int size) {
    Census census;
    census.size = size;
    census.count = 0;
    census.array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        census.array[i] = -1;
    }
    return census;
}

Census addToCensus(Census c, int value) {
    for (int i = 0; i < c.size; i++)
    {
        if (c.array[i] == -1)
        {
            c.array[i] = value;
            break;
        }
    }
    return c;
}
int main(void) {
    Census c = createCensus(5);

    c.array[0] = 4;
    c.array[1] = 0;
    c.array[2] = 1;

    displayArray(c.array, 5);
    addToCensus(c, 5);
    displayArray(c.array, 5);
    free(c.array);
    return 0;
}
