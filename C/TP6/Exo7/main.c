#include "utils.h"

int     main(void)
{
    int w = 4;
    int h = 3;

    srand(time(0));

    Matrix m = createMatrix(w, h);

    fillRandom(m);
    printMatrix(m);
    for (int i = 0; i < m.height; i++) 
        free(m.data[i]);
    free(m.data);
    return(0);
}