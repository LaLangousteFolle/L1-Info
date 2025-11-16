#include "Exo2-5.h"

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
        printf("Vos nombres ne sont pas corrects.\n");
        printf("Entrez le min : ");
        scanf("%lf", &min);
        printf("Entrez le max : ");
        scanf("%lf", &max);
    }
    if (check(min, max))
        printf("Vos nombres sont corrects.\n");
    modify(min, max);
    if (! check(min, max))
        printf("Resultat min : %lf et max : %lf (ils ne respectent pas l'ordre)\n",min , max);
    else
        printf("Resultat min : %lf et max : %lf (ils respectent l'ordre)\n",min , max);

    return(0);
}
