#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int     main(void)
{
    srand(time(0));
    int     size;
    printf("Veuillez specifier la taille du tableau : ");
    scanf("%d", &size);
    double *tab = malloc((sizeof(double)*size));
    for (int i  = 0; i < size; i++)
    {
        tab[i] = rand()% ( 101);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", tab[i]);
    }
    free(tab);
    return(0);
}
