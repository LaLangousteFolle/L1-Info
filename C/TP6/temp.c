#include <stdlib.h>

double *getPositive(double *tab[])
{
    int size  = 0;
    while (tab)
    {
        size++;
    }
    double *tab2 = malloc(sizeof(double) * size);
    for (int i = 0; i < size;i++)
    {
        if (tab[i] >=0)
            tab2[i] = tab2[i];
    }
    return(tab2);
}