#include <stdio.h>

int     main(void)
{
    int grades[5] = {13, 9, 16, 15, 19};

    printf("Valeur du troisieme element : %i\n", grades[2]);

    grades[3] = 14;

    printf("Tableau apres modif: %i, %i, %i, %i, %i\n", grades[0], grades[1], grades[2], grades[3], grades[4]);

    return(0);
}
