#include <stdbool.h>
bool    isPositive(double *user_value)
{
    if (*user_value < 0)
        return(false);
    else
        return(true);
}

void    modify(double *user_value)
{
    if (isPositive(user_value)!=true)
        *user_value = *user_value * 3;
    else
        *user_value = *user_value / 2;
}
