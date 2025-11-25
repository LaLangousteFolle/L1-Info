#include <bits/floatn-common.h>
void    displayArray(int tab[], int size)
{
    for (int i = 0; i <=size; i++)
        __builtin_printf("%i ", tab[i]);
}

int     main(void)
{
    int tab[100];
    for ( int i = 0; i < 100; i++)
        tab[i] = i * 2;
    displayArray(tab, 99);
    return(0);
}
