#include "Exo2-5bis.h"

int     main(void)
{
    bool        user;
    double      min, max;

    printf("Entrez le min : ");
    scanf("%lf", &min);
    printf("Entrez le max : ");
    scanf("%lf", &max);

    if (! check(min, max))
    {
        swap(&min, &max);
        printf("min et max inversés automatiquement pour non respect de la consigne.\n");
    }
    modify(&min, &max);
    if (! check(min, max))
        printf("Resultat min : %lf et max : %lf (ils ne respectent pas l'ordre)\n",min , max);
    else
        printf("Resultat min : %lf et max : %lf (ils respectent l'ordre)\n",min , max);

    return(0);
}
