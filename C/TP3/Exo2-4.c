#include<stdio.h>

void    distributeBonus(double *salary_1, double  *salary_2, double  *salary_3, double  *bonus)
{
    double  bonus_per_employe = *bonus/3;

    *salary_1 += bonus_per_employe;
    *salary_2 += bonus_per_employe;
    *salary_3 += bonus_per_employe;

}

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
