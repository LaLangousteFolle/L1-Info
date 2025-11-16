<<<<<<< HEAD:C/TP3/Exo2-6/main.c
#include "Exo2-6.h"
=======
#include <stdio.h>

void    swap(int *pMin, int *pMax)
{
    int buff;

    buff = *pMin;
    *pMin = *pMax;
    *pMax = *pMin;
}

void    sort(int *a, int *b, int *c)
{
    if (*a < *b)
        swap(a, b);
    if (*b < *c)
        swap(b,c);
}

>>>>>>> c02a6269ef3604d0250f21d4f77eb8ff0ad2558a:C/TP3/Exo2-6.c
int     main(void)
{
    int     a, b, c;

    printf("Valeur de a : ");
    scanf("%d",&a);
    printf("Valeur de b : ");
    scanf("%d", &b);
    printf("Valeur de c : ");
    scanf("%d", &c);
    sort(&a,&b,&c);
    return(0);
}
