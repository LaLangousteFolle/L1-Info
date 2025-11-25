#include "utils.h"

void    displayArray(int tab[], int size)
{
    for (int i = 0; i <=size; i++)
        printf("%i ", tab[i]);
}

int     main(void)
{
    int tab[100];
    for (int i = 0; i < 100; i++)
        tab[i] = i;
    displayArray(tab, 99);
    return(0);
}
