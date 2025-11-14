#include <stdio.h>

void minMax(int *a, int*b, int*c)
{
    int buff_a, buff_c;

    buff_a = *a;
    buff_c = *c;
    if (buff_a > *b)
        buff_a = *b;
    if (buff_a > *c)
        buff_a = *c;

    if (buff_c < *a)
        buff_c = *a;
    if (buff_c < *b)
        buff_c = *b;

    *a = buff_a;
    *c = buff_c;
}

int     main(void)
{
    int a, b, c;
    printf("saisir a :");
    scanf("%i", &a);
    printf("saisir b :");
    scanf("%i", &b);
    printf("saisir c :");
    scanf("%i", &c);

    minMax(&a, &b, &c);
    printf("Le minimum vaut %i, et le maximum vaut %i", a,c);
    return(0);
}
