#include <stdlib.h>
#include <stdio.h>

void       creatTab(double *array, int size)
{
    double *tab = malloc((sizeof(double)*size));
    for (int i  = 0; i < size; i++)
    {
        tab[i] = rand()% ( 101);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", tab[i]);
    }
}

int     main(void)
{
    int size;
    printf("Veuillez entrer la taille souhaitee : ");
    scanf("%d", &size);
    double *array;
    creatTab(array, size);
    for (int i = 0; i < size; i++)
        printf("%lf", array[i]);
    free(array);
    return(0);
}