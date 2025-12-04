#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *pI = malloc(sizeof(int));
    *pI = 42;
    printf("%p\n", pI);
    free(pI);
    return(0);
}
