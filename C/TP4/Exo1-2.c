#include "utils.h"

int     main(void)
{
    int tab1[3] = {1, 2, 3};
    displayArray(tab1, 2);
    double tab2[6] = {1.5, 2.8, 0.7};
    tab2[5] = 12.92;

    for (int i = 0; i <=5; i++)
        printf("%lf ", tab2[i]);

    int tab3[5];

    tab3[0] = 9;
    tab3[1] = 4;
    tab3[2] = 6;
    tab3[3] = 8;
    tab3[4] = 3;
    displayArray(tab3, 4);
    return(0);
}
