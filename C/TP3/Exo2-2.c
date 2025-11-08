#include <stdio.h>

void    getOpposite(int *user_entry)
{
    *user_entry = (*user_entry * (-1));
}

int     main(void)
{
    int     user_entry;
    printf("Veuille entrer un nombre : ");
    scanf("%i", &user_entry);
    getOpposite(&user_entry);
    printf("Son oppose est : %i\n",user_entry);
    return(0);
}
