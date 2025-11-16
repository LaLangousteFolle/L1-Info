#include "Exo2-3.h"

int     main(void)
{
    double user_value;
    printf("Veuillez entrer une valeur : ");
    scanf("%lf",&user_value);
    modify(&user_value);
    printf("Valeur apres modification : %lf\n", user_value);
    return(0);
}
