#include "Exo2-4.h"

int     main(void)
{
    double     salary_1, salary_2, salary_3, bonus;

    printf("Salaire du premier salarie : ");
    scanf("%lf", &salary_1);
    printf("Salaire du deuxieme salarie : ");
    scanf("%lf",&salary_2);
    printf("Salaire du troisiem salarie : ");
    scanf("%lf", &salary_3);
    printf("Montant de la prime : ");
    scanf("%lf", &bonus);
    distributeBonus(&salary_1, &salary_2, &salary_3, &bonus);
    printf("Salaire total des salaries : %lf, %lf, %lf", salary_1, salary_2, salary_3);
    return(0);
}
