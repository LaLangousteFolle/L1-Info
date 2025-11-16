#include "Exo3-2.h"
int     main(void)
{
    int a, b, c;
    printf("saisir a :");
    scanf("%i", &a);
    printf("saisir b :");
    scanf("%i", &b);
    printf("saisir c :");
    scanf("%i", &c);

    minMax(&a, &b, &c);
    printf("Le minimum vaut %i, et le maximum vaut %i", a,c);
    return(0);
}
