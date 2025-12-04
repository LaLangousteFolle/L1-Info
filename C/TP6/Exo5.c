#include <stdlib.h>
#include <stdio.h>

void reallocateMemory(int **pointer, int value)
{
    if (*pointer != NULL)
    {
        free(*pointer);
        free(pointer);
    }

    pointer = malloc(sizeof(int));
    *pointer = malloc(sizeof(int));
    **pointer = value;
    printf("emplacement memoire : %p\n", *pointer);
    printf("Valeur : %d\n", **pointer);
}

int     main(void)
{
    int *norman = NULL;
    reallocateMemory(&norman, 8);
    reallocateMemory(&norman, 80);
    reallocateMemory(&norman, 800);
    free(norman);
    return(0);
}
