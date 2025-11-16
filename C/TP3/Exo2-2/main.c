#include "Exo2-2.h"

int     main(void)
{
    int     user_entry;
    printf("Veuille entrer un nombre : ");
    scanf("%i", &user_entry);
    getOpposite(&user_entry);
    printf("Son oppose est : %i\n",user_entry);
    return(0);
}
