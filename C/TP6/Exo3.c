#include <stdlib.h>

int *getPositiveValue(int *tab, int size)
{
    int *tab2 = malloc(sizeof(int) * size);
    for (int i = 0; i < size;i++)
    {
        if (tab[i] >=0)
            tab2[i] = tab2[i];
    }
    return(tab2);
}
