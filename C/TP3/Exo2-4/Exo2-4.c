void    distributeBonus(double *salary_1, double  *salary_2, double  *salary_3, double  *bonus)
{
    double  bonus_per_employe = *bonus/3;

    *salary_1 += bonus_per_employe;
    *salary_2 += bonus_per_employe;
    *salary_3 += bonus_per_employe;

}
