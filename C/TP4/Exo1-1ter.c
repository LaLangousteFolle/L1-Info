#include <stdio.h>

void    displayArray(int tab[], int size)
{
    for (int i = 0; i <=size; i++)
        printf("%i ", tab[i]);
}

int     main(void)
{
    int grades[5] = {13, 9, 16, 15, 19};
    displayArray(grades, 4);
    return(0);
}
