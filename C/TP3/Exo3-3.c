#include <stdio.h>
#include <stdbool.h>

void logic(bool a, bool b, bool *and, bool *or, bool *xor)
{
    *and = (a && b);
    *or  = (a || b);
    *xor = (a != b);
}

int     main(void)
{
    bool a,b;
    bool and, or, xor;
    printf("Premier valeur : ");
    scanf("%d", &a);
    printf("Deuxieme valeur : ");
    scanf("%d", &b);

    logic(a, b, &and, &or, &xor);
    printf("AND : %d\n", and);
    printf("OR : %d\n", or);
    printf("XOR : %B\n", xor);
    return(0);
}
