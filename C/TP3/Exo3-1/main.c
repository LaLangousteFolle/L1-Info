#include "Exo3-1.h"
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
