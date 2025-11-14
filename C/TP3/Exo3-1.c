#include <stdio.h>

void    arithmetic(double *a, double *b)
{
    double buff_a,buff_b;

    buff_a = *a;
    buff_b = *b;
    *a = buff_b + buff_a;
    *b = buff_a * buff_b;
}

int     main(void)
{
    double a,b;
    printf("Saisir a : ");
    scanf("%lf", &a);
    printf("Saisir b : ");
    scanf("%lf", &b);

    arithmetic(&a, &b);

    printf("Somme = %lf \n", a);
    printf("Produit = %lf \n", b);

    return(0);
}
