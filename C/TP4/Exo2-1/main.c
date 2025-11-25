#include "Exo2-1.h"

int     main(void)
{
    int tab1[100];
    int tab2[100];

    initializeHundredCasu(tab1);
    initializeHundredEven(tab2);
    displayArray(tab1, 99);
    displayArray(tab2, 99);
    return(0);
}
