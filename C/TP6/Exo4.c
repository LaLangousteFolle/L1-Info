#include <stdlib.h>
#include <stdbool.h>

void leakmemory(void)
{
    while (true)
    {
        double *loop = malloc(sizeof(double)*100);
        free(loop);
    }
}

int     main(void)
{
    leakmemory();
    return(0);
}
