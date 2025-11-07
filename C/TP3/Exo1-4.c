#include <stdbool.h>

int     main(void)
{
    double  price;
    bool    isActive;
    double  *pPrice;
    bool    *pIsActive;

    price = 100.50;
    isActive = true;
    pPrice = &price;
    pIsActive = &isActive;
    *pPrice = 150.75;
    *pIsActive = false;
    __builtin_printf("bool : %b",isActive);
    __builtin_printf("double : %lf", price);
    return(0);
}
