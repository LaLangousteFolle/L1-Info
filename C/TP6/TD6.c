#include <stdlib.h>

double *getPositive(double *tab, int size)
{
    double *tab2 = malloc(sizeof(double) * size);
    for (int i = 0; i < size;i++)
    {
        if (tab[i] >=0)
            tab2[i] = tab[i];
    }
    __builtin_printf("%d", size);
    return(tab2);
}

int main(void)
{
    double tab[5] = {-2.0,3.5,4.9,-10.1,0.4};
    getPositive(tab, 5);
    return(0);
}
