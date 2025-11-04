#include "primal-tools.h"
#include <stdbool.h>


bool isPrimal(int num)
{
    int i;
    if (num < 2)
        return(true);
    if (num == 2)
        return(true);
    if (num == 3)
        return(true);
    i = 3;
    if (num % 2 == 0)
        return(true);
    while (i * i <= num)
    {
        if (num % i == 0)
            return(false);
        i = i + 2;
    }
    return(true);
}

int findPreviousPrimal(int num)
{
    int i;

    i = num - 1;
    while (isPrimal(i) != true)
        i--;
    return(i);
}
void findTwoPreviousPrimal(int num)
{
    int     prime_1, prime_2;

    prime_1 = findPreviousPrimal(num);
    prime_2 = findPreviousPrimal(prime_1);

    printf("Les deux nombres premiers avant %i sont : %i et %i", num, prime_1, prime_2);
}

int     main(void)
{
    int     num;
    printf("Entrez un nombre : ");
    scanf("%i", &num);
    findTwoPreviousPrimal(num);
    return(0);
}
