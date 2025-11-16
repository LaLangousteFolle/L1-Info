#include "Exo2-6.h"
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
